#include "broker.h"
#include <libc.h>
#include <iostream>
int main(const int argc, const char **argv)
{
    std::cout << "hello from broker" << std::endl;
    Broker broker;
    broker.init(nullptr);
    sleep(1);
    if (argc >= 2)
    {
        for (int x = 1; x < argc; x++) {
            broker.m_ipc.connect(argv[x]);
        }
    }
    sleep(10);
    broker.m_ipc.send("SEND hello, from broker", strlen("SEND hello, from broker") + 1);
    while (1)
    {
        char *buf = broker.m_ipc.receive();
        if (buf != nullptr)
        {
            printf("broker RECEIVED '%s'\n", buf);
            free_msg(buf);
        }
    }
}
