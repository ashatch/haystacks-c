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

  //ec3a49ae-927a-407b-a220-e86d1a4f084f

  u->value[0] = u->value[0] |= hex2int(str[0])  << 12;
  u->value[0] = u->value[0] |= hex2int(str[1])  << 8;
  u->value[0] = u->value[0] |= hex2int(str[2])  << 4;
  u->value[0] = u->value[0] |= hex2int(str[3])  << 0;

//   u->lsb = 0x000000000000;
//   u->msb = 0x000000000000;

//   u->msb = u->msb |= hex2int(str[0])  << 60;
//   u->msb = u->msb |= hex2int(str[1])  << 56;
//   u->msb = u->msb |= hex2int(str[2])  << 52;
//   u->msb = u->msb |= hex2int(str[3])  << 48;
//   u->msb = u->msb |= hex2int(str[4])  << 44;
//   u->msb = u->msb |= hex2int(str[5])  << 40;
//   u->msb = u->msb |= hex2int(str[6])  << 36;
//   u->msb = u->msb |= hex2int(str[7])  << 32;

//   u->msb = u->msb |= hex2int(str[9])  << 28;
//   u->msb = u->msb |= hex2int(str[10]) << 24;
//   u->msb = u->msb |= hex2int(str[11]) << 20;
//   u->msb = u->msb |= hex2int(str[12]) << 16;

//   u->msb = u->msb |= hex2int(str[14]) << 12;
//   u->msb = u->msb |= hex2int(str[15]) << 8;
//   u->msb = u->msb |= hex2int(str[16]) << 4;
//   u->msb = u->msb |= hex2int(str[17]) << 0;

//   u->lsb = u->lsb |= hex2int(str[19]) << 60;
//   u->lsb = u->lsb |= hex2int(str[20]) << 56;
//   u->lsb = u->lsb |= hex2int(str[21]) << 52;
//   u->lsb = u->lsb |= hex2int(str[22]) << 48;

//   u->lsb = u->lsb |= hex2int(str[24]) << 44;
//   u->lsb = u->lsb |= hex2int(str[25]) << 40;
//   u->lsb = u->lsb |= hex2int(str[26]) << 36;
//   u->lsb = u->lsb |= hex2int(str[27]) << 32;
//   u->lsb = u->lsb |= hex2int(str[28]) << 28;
//   u->lsb = u->lsb |= hex2int(str[29]) << 24;
//   u->lsb = u->lsb |= hex2int(str[30]) << 20;
//   u->lsb = u->lsb |= hex2int(str[31]) << 16;
//   u->lsb = u->lsb |= hex2int(str[32]) << 12;
//   u->lsb = u->lsb |= hex2int(str[33]) << 8;
//   u->lsb = u->lsb |= hex2int(str[34]) << 4;
//   u->lsb = u->lsb |= hex2int(str[35]) << 0;
  
  return u;
}
