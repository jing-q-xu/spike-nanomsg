#include "client.h"
Client::Client(const char *name) : m_name(name), m_node() {

}

int Client::init(const char *local) {
    m_node.init(local);
    // sleep(5);
    m_node.connect(BROKER_IPC);
    return 0;
}

int Client::connect(const char *remote) {
    m_node.connect(remote);
    return 0;
}
