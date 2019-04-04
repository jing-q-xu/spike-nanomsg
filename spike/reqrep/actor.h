#ifndef __ACTOR_H__
#define __ACTOR_H__
struct Actor
{
    virtual int msg_received(const char *msg, int len) = 0;
    virtual ~Actor() {}
};
#endif