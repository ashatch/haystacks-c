#ifndef __UUID_H__
#define __UUID_H__

struct uuid {
  long long msb;
  long long lsb;
};

extern struct uuid* uuid_from_string(char *str);

#endif