#ifndef __CLIENT_H__
#define __CLIENT_H__
#include <string>
struct Client
{
    explicit Client(const char* address);
    int send(const char* buf, int size);
private:
    std::string m_address;
    int m_socket;
};
#endif