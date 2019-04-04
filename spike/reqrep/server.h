#ifndef __SERVER_H__
#define __SERVER_H__
#include <string>
#include "actor.h"

struct  Server
{
    explicit Server(const char* address);
    int receive(Actor &actor);
private:
    std::string m_address;
    int m_socket;
};
#endif