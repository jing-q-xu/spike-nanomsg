#ifndef __NODE_H__
#define __NODE_H__
struct Node
{
    Node();
    int init(const char *local);
    void connect(const char *remote);
    int send(const void *buf, int size);
    char *receive();
    ~Node();
private:
    static const int INVALID_SOCKET_ID = -1;
    int m_bind_socket;
    int m_connect_socket;
};
#define BROKER_IPC "ipc:///tmp/broker.ipc"
void free_msg(char *&msg);

#endif