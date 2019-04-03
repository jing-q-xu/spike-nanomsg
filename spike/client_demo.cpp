#include "client.h"
#include <libc.h>
#include <iostream>
int main(const int argc, const char **argv)
{
    if (argc < 4) {
        std::cout << "usage: client name local remote1 [remote2]....." << std::endl;
        return 0;
    }
    std::cout << "hello from " << argv[1] << std::endl;
    Client client(argv[1]);
    client.init(argv[2]);
    sleep(1);
    for (int x = 3; x < argc; x++) {
        client.connect(argv[x]);
    }
    sleep(1);
    
    std::string greeting("SEND hello, from client: ");
    greeting.append(argv[1]);
    client.m_node.send(greeting.c_str(), greeting.length() + 1);
    while (1)
    {
        char *buf = client.m_node.receive();
        if (buf != nullptr)
        {
            std::cout << "RECEIVED FROM BUS: " << "client: " << argv[1] << ", buf: " << buf << std::endl;
            free_msg(buf);
        }
    }
    return 0;
}