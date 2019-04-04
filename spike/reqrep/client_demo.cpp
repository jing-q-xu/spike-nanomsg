#include "client.h"
#include <iostream>
#include "msg.h"
int main (const int argc, const char **argv)
{
    const char *url = argv[1];
    Client client(url);
    Greeting greeting;
    greeting.count = 0;
    strcpy(greeting.buf, "hello from client");
    while(1)
    {
        client.send((const char*)(&greeting), sizeof(greeting));
        greeting.count++;
        // if (greeting.count % 100 == 0)
        {
            std::cout << "client send count: " << greeting.count << std::endl;
        }
    }
}