#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "dict.h"

int fast_compare( const char *ptr0, const char *ptr1, int len ){
    int fast = len/sizeof(size_t) + 1;
    int offset = (fast-1)*sizeof(size_t);
    int current_block = 0;
    if( len <= sizeof(size_t)){ fast = 0; }
    size_t *lptr0 = (size_t*)ptr0;
    size_t *lptr1 = (size_t*)ptr1;
    while( current_block < fast ){
        if( (lptr0[current_block] ^ lptr1[current_block] )){
        int pos;
        for(pos = current_block*sizeof(size_t); pos < len ; ++pos ){
        if( (ptr0[pos] ^ ptr1[pos]) || (ptr0[pos] == 0) || (ptr1[pos] == 0) ){
        return  (int)((unsigned char)ptr0[pos] - (unsigned char)ptr1[pos]);
              }
            }
          }
        ++current_block;
    }
    while( len > offset ){
        if( (ptr0[offset] ^ ptr1[offset] )){ 
        return (int)((unsigned char)ptr0[offset] - (unsigned char)ptr1[offset]); 
          }
        ++offset;
    }
    return 0;
}

struct elt {
    struct elt *next;
    char *key;
    char *value;
};

struct dict {
    int size;           /* size of the pointer table */
    int n;              /* number of elements stored */
    struct elt **table;
};

#define INITIAL_SIZE (30000)
#define GROWTH_FACTOR (4)
#define MAX_LOAD_FACTOR (1)

/* dictionary initialization code used in both DictCreate and grow */
Dict
internalDictCreate(int size)
{
    Dict d;
    int i;

    d = malloc(sizeof(*d));

    d->size = size;
    d->n = 0;
    d->table = malloc(sizeof(struct elt *) * d->size);

    for(i = 0; i < d->size; i++) d->table[i] = 0;

    return d;
}

Dict
DictCreate(void)
{
    return internalDictCreate(INITIAL_SIZE);
}

void
DictDestroy(Dict d)
{
    int i;
    struct elt *e;
    struct elt *next;

    for(i = 0; i < d->size; i++) {
        for(e = d->table[i]; e != 0; e = next) {
            next = e->next;

            free(e->key);
            free(e->value);
            free(e);
        }
    }

    free(d->table);
    free(d);
}

#define MULTIPLIER (512)

static unsigned long
hash_function(const char *s)
{
    unsigned const char *us;
    unsigned long h;

    h = 0;

    for(us = (unsigned const char *) s; *us; us++) {
        h = h * MULTIPLIER + *us;
    }

    return h;
}

static void
grow(Dict d)
{
    Dict d2;            /* new dictionary we'll create */
    struct dict swap;   /* temporary structure for brain transplant */
    int i;
    struct elt *e;

    d2 = internalDictCreate(d->size * GROWTH_FACTOR);

    for(i = 0; i < d->size; i++) {
        for(e = d->table[i]; e != 0; e = e->next) {
            /* note: this recopies everything */
            /* a more efficient implementation would
              * patch out the strdups inside DictInsert
              * to avoid this problem */
            DictInsert(d2, e->key, e->value);
        }
    }

    /* the hideous part */
    /* We'll swap the guts of d and d2 */
    /* then call DictDestroy on d2 */
    swap = *d;
    *d = *d2;
    *d2 = swap;

    DictDestroy(d2);
}

/* insert a new key-value pair into an existing dictionary */
void
DictInsert(Dict d, const char *key, const char *value)
{
    struct elt *e;
    unsigned long h;

    assert(key);
    assert(value);

    e = malloc(sizeof(*e));

    assert(e);

    e->key = strdup(key);
    e->value = strdup(value);

    h = hash_function(key) % d->size;

    e->next = d->table[h];
    d->table[h] = e;

    d->n++;

    /* grow table if there is not enough room */
    if(d->n >= d->size * MAX_LOAD_FACTOR) {
        grow(d);
    }
}

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
const char *
DictSearch(Dict d, const char *key)
{
    struct elt *e;

    for(e = d->table[hash_function(key) % d->size]; e != 0; e = e->next) {
        if(!fast_compare(e->key, key, 1)) {
            /* got it */
            return e->value;
        }
    }

    return 0;
}

/* delete the most recently inserted record with the given key */
/* if there is no such record, has no effect */
void
DictDelete(Dict d, const char *key)
{
    struct elt **prev;          /* what to change when elt is deleted */
    struct elt *e;              /* what to delete */

    for(prev = &(d->table[hash_function(key) % d->size]); 
        *prev != 0; 
        prev = &((*prev)->next)) {
        if(!fast_compare((*prev)->key, key, 1)) {
            /* got it */
            e = *prev;
            *prev = e->next;

            free(e->key);
            free(e->value);
            free(e);

            return;
        }
    }
}