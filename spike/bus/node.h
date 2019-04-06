#ifndef __NODE_H__
#define __NODE_H__
struct Actor;
struct Node
{
    Node();
    int init(const char *local);
    void connect(const char *remote);
    int send(const void *buf, int size);
    int receive(Actor &actor);
    ~Node();
private:
    static const int INVALID_SOCKET_ID = -1;
    int m_bind_socket;
    int m_connect_socket;
};

#endif