#include "broker.h"
#include <stdio.h>
#include <string>
namespace {
bool is_ipc(const char* address) {
    std::string helper(address);
    // if (helper.substr("ipc:") == 0) {
    //     return true;
    // }
    return false;
}
}
void Broker::init(const char* local_tcp) {
    m_ipc.init(BROKER_IPC);
    m_tcp.init(local_tcp);
}

void Broker::connect(const char *remote) {
    m_ipc.connect(remote);
}
