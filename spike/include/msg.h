#ifndef __MSG_H__
#define __MSG_H__
#include <stdlib.h>
struct Greeting
{
    Greeting() : count(0)
    {
        strcpy(buf, "hello from client");
    }
    int count;
    char buf[128];
};

#endif