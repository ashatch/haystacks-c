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

  u->value[0] = 0x0000;
  u->value[1] = 0x0000;
  u->value[2] = 0x0000;
  u->value[3] = 0x0000;

  u->value[0] = u->value[0] |= hex2int(str[0])   << 28;
  u->value[0] = u->value[0] |= hex2int(str[1])   << 24;
  u->value[0] = u->value[0] |= hex2int(str[2])   << 20;
  u->value[0] = u->value[0] |= hex2int(str[3])   << 16;

  u->value[0] = u->value[0] |= hex2int(str[4])   << 12;
  u->value[0] = u->value[0] |= hex2int(str[5])   << 8;
  u->value[0] = u->value[0] |= hex2int(str[6])   << 4;
  u->value[0] = u->value[0] |= hex2int(str[7])   << 0;

  u->value[1] = u->value[1] |= hex2int(str[9])   << 28;
  u->value[1] = u->value[1] |= hex2int(str[10])  << 24;
  u->value[1] = u->value[1] |= hex2int(str[11])  << 20;
  u->value[1] = u->value[1] |= hex2int(str[12])  << 16;

  u->value[1] = u->value[1] |= hex2int(str[14])  << 12;
  u->value[1] = u->value[1] |= hex2int(str[15])  << 8;
  u->value[1] = u->value[1] |= hex2int(str[16])  << 4;
  u->value[1] = u->value[1] |= hex2int(str[17])  << 0;

  u->value[2] = u->value[2] |= hex2int(str[19])  << 12;
  u->value[2] = u->value[2] |= hex2int(str[20])  << 8;
  u->value[2] = u->value[2] |= hex2int(str[21])  << 4;
  u->value[2] = u->value[2] |= hex2int(str[22])  << 0;

  u->value[2] = u->value[2] |= hex2int(str[24])  << 12;
  u->value[2] = u->value[2] |= hex2int(str[25])  << 8;
  u->value[2] = u->value[2] |= hex2int(str[26])  << 4;
  u->value[2] = u->value[2] |= hex2int(str[27])  << 0;

  u->value[3] = u->value[3] |= hex2int(str[28])  << 12;
  u->value[3] = u->value[3] |= hex2int(str[29])  << 8;
  u->value[3] = u->value[3] |= hex2int(str[30])  << 4;
  u->value[3] = u->value[3] |= hex2int(str[31])  << 0;

  u->value[3] = u->value[3] |= hex2int(str[32])  << 12;
  u->value[3] = u->value[3] |= hex2int(str[33])  << 8;
  u->value[3] = u->value[3] |= hex2int(str[34])  << 4;
  u->value[3] = u->value[3] |= hex2int(str[35])  << 0;

  return u;
}
