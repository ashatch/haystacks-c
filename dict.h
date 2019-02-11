// http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html

typedef struct dict *Dict;

/* create a new empty dictionary */
Dict DictCreate(void);

/* destroy a dictionary */
void DictDestroy(Dict);

/* insert a new key-value pair into an existing dictionary */
void DictInsert(Dict, const char *key);

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
const int DictSearch(Dict, const char *key);

/* delete the most recently inserted record with the given key */
/* if there is no such record, has no effect */
void DictDelete(Dict, const char *key);
