#include <iostream>
#include <unistd.h>
#include "client.h"
#include "msg.h"
int main (const int argc, const char **argv)
{
    const char *url = argv[1];
    Client client(url);
    Greeting greeting;
    while(1)
    {
        client.send((const char*)(&greeting), sizeof(greeting));
        // usleep(1000);
        greeting.count++;
        // if (greeting.count % 100 == 0)
        {
            std::cout << "client send count: " << greeting.count << std::endl;
        }
    }
    sleep(1000);
    return 0;
}