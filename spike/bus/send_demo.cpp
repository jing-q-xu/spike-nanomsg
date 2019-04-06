#include <iostream>
#include <unistd.h>
#include "node.h"
#include "msg.h"

int main (const int argc, const char **argv)
{
    if(argc < 2)
    {
        std::cout << "usage: client local" << std::endl;
    }
    const char *url = argv[1];
    Greeting greeting;
    Node client;
    client.init(argv[1]);
    for (int i = 2; i < argc; i++)
    {
        client.connect(argv[i]);
    }

    while(1)
    {
        client.send((const char*)(&greeting), sizeof(greeting));
        // usleep(10);
        greeting.count++;
        if (greeting.count % 1000 == 0)
        {
            std::cout << "client send count: " << greeting.count << std::endl;
        }
    }
    return 0;
}