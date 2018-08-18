#ifndef __UUID_H__
#define __UUID_H__

struct uuid {
  unsigned long long msb;
  unsigned long long lsb;
};

extern struct uuid* uuid_from_string(char *str);

#endif