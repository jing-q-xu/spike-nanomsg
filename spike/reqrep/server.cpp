#include "server.h"
#include <iostream>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>

namespace
{
const char * ACK = "ACK";
}
Server::Server(const char* address) : m_address(address), m_socket(-1)
{
    m_socket = nn_socket (AF_SP, NN_REP);
    nn_bind(m_socket, address);
}

int Server::receive(Actor &actor)
{
    char *buf = NULL;
    int bytes = nn_recv (m_socket, &buf, NN_MSG, 0);
    nn_send(m_socket, ACK, strlen(ACK) + 1, 0);
    actor.msg_received(buf, bytes);
    nn_freemsg(buf);
    return 0;
}

Server::~Server()
{
    nn_shutdown(m_socket, 0);
}

