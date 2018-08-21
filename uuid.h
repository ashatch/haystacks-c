#ifndef __UUID_H__
#define __UUID_H__

#include<stdlib.h>

struct uuid {
  uint32_t value[4];
};

extern struct uuid* uuid_from_string(char *str);

#endif