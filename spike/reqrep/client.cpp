#include "client.h"

#include <libc.h>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>
#include <iostream>

Client::Client(const char* address) : m_address(address), m_socket(-1)
{
    m_socket = nn_socket (AF_SP, NN_REQ);
    nn_connect(m_socket, address);
    int to = 1000;
    nn_setsockopt(m_socket, NN_SOL_SOCKET, NN_RCVTIMEO, &to, sizeof(to));
    to = 10;
    nn_setsockopt(m_socket, NN_SOL_SOCKET, NN_REQ_RESEND_IVL, &to, sizeof(to));
}

int Client::send(const char* buf, int size)
{
    int bytes = nn_send (m_socket, buf, size, 0);
    if (bytes != size)
    {
        std::cout << "client: failed to send data, size: " << bytes << std::endl;
        return -1;
    }
    return 0;
    // char *ack = nullptr;
    // bytes = nn_recv(m_socket, &ack, NN_MSG, 0);
    // return bytes >= 0;
}
