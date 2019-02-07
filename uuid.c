#include "uuid.h"
#include <stdlib.h>
#include <stdio.h>

unsigned long long hex2int(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    return -1;
}

struct uuid* uuid_from_string(char *str) {
  struct uuid *u = malloc(sizeof(struct uuid));

  for (int i = 0; i < 8; i++) {
    u->value[i] = 0x0;
  }
  
  u->value[0] = u->value[0] |= hex2int(str[0])   << 4;
  u->value[0] = u->value[0] |= hex2int(str[1])   << 0;
  u->value[1] = u->value[1] |= hex2int(str[2])   << 4;
  u->value[1] = u->value[1] |= hex2int(str[3])   << 0;

  u->value[2] = u->value[2] |= hex2int(str[4])   << 4;
  u->value[2] = u->value[2] |= hex2int(str[5])   << 0;
  u->value[3] = u->value[3] |= hex2int(str[6])   << 4;
  u->value[3] = u->value[3] |= hex2int(str[7])   << 0;

  u->value[4] = u->value[4] |= hex2int(str[9])   << 4;
  u->value[4] = u->value[4] |= hex2int(str[10])  << 0;
  u->value[5] = u->value[5] |= hex2int(str[11])  << 4;
  u->value[5] = u->value[5] |= hex2int(str[12])  << 0;

  u->value[6] = u->value[6] |= hex2int(str[14])  << 4;
  u->value[6] = u->value[6] |= hex2int(str[15])  << 0;
  u->value[7] = u->value[7] |= hex2int(str[16])  << 4;
  u->value[7] = u->value[7] |= hex2int(str[17])  << 0;

  u->value[8] = u->value[8] |= hex2int(str[19])  << 4;
  u->value[8] = u->value[8] |= hex2int(str[20])  << 0;
  u->value[9] = u->value[9] |= hex2int(str[21])  << 4;
  u->value[9] = u->value[9] |= hex2int(str[22])  << 0;

  u->value[10] = u->value[10] |= hex2int(str[24])  << 4;
  u->value[10] = u->value[10] |= hex2int(str[25])  << 0;
  u->value[11] = u->value[11] |= hex2int(str[26])  << 4;
  u->value[11] = u->value[11] |= hex2int(str[27])  << 0;

  u->value[12] = u->value[12] |= hex2int(str[28])  << 4;
  u->value[12] = u->value[12] |= hex2int(str[29])  << 0;
  u->value[13] = u->value[13] |= hex2int(str[30])  << 4;
  u->value[13] = u->value[13] |= hex2int(str[31])  << 0;

  u->value[14] = u->value[14] |= hex2int(str[32])  << 4;
  u->value[14] = u->value[14] |= hex2int(str[33])  << 0;
  u->value[15] = u->value[15] |= hex2int(str[34])  << 4;
  u->value[15] = u->value[15] |= hex2int(str[35])  << 0;

  return u;
}
