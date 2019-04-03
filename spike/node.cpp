#include "node.h"
#include <stdio.h>
#include <nanomsg/nn.h>
#include <nanomsg/bus.h>
#include <iostream>
Node::Node() 
        : m_bind_socket(INVALID_SOCKET_ID)
        , m_connect_socket(INVALID_SOCKET_ID) {
}

Node::~Node() {
    if (m_bind_socket != INVALID_SOCKET_ID) {
        nn_shutdown(m_bind_socket, 0);
    }
    if (m_connect_socket != INVALID_SOCKET_ID) {
        nn_shutdown(m_connect_socket, 0);
    }
}

int Node::init(const char *local) {
    m_bind_socket = nn_socket(AF_SP, NN_BUS);
    m_connect_socket = nn_socket(AF_SP, NN_BUS);
    nn_bind(m_bind_socket, local);
    // std::cout << "Node::init:" << local << std::endl;
    int to = 100;
    nn_setsockopt(m_bind_socket, NN_SOL_SOCKET, NN_RCVTIMEO, &to, sizeof(to));
    return 0;
}

void Node::connect(const char *remote) {
    // std::cout << "Node::connected" << remote << std::endl;
    nn_connect(m_connect_socket, remote);
}

int Node::send(const void *buf, int size) {
    std::cout << "Node::send: " << (char *)buf << std::endl;
    return nn_send(m_connect_socket, buf, size, 0);
}

char *Node::receive() {
    char *buf = NULL;
    int recv = nn_recv(m_bind_socket, &buf, NN_MSG, 0);
    if (recv >= 0)
    {
        return buf;
    }
    return nullptr;
}

void free_msg(char *&msg) {
    if (msg == nullptr) 
    {
        return;
    }
    nn_freemsg(msg);
    msg = nullptr;
}