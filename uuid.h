#ifndef __UUID_H__
#define __UUID_H__

#include<stdlib.h>

struct uuid {
  uint8_t value[16];
};

extern struct uuid* uuid_from_string(char *str);

#endif