#ifndef __BROKER_H__
#define __BROKER_H__
#include "node.h"
struct  Broker
{
    Broker() {}
    void init(const char* network_local);
    void connect(const char *remote);
// private:
    Node m_ipc;
    Node m_tcp;
};

#endif
