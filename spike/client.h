#ifndef __CLINET_H__
#define __CLINET_H__
#include "node.h"
#include <string>
struct Client
{
    Client(const char *name);
    int init(const char *local);
    int connect(const char *remote);
// private:
    Node m_node;
    std::string m_name;
};

#endif
