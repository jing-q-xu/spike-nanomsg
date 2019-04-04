#include "server.h"
#include <iostream>
#include "msg.h"

namespace
{
int count = -1;
struct DummyActor : Actor
{
    int msg_received(const char *msg, int len)
    {
        if(len == sizeof(Greeting))
        {
            const Greeting* greet = (const Greeting*)msg;
            int sequence = greet->count;
            if(count != -1)
            {
                if(count + 1 != sequence)
                {
                    std::cout << "error, expect:" << count + 1 << " received:" << sequence << std::endl;
                }
            }
            count = sequence;
            if (count % 100 == 0)
            {
                std::cout << "client send count: " << count << std::endl;
            }
            }
            else
            {
                std::cout << "error, unexpected length received:" << std::endl;
            }
        return 0;
    }
}dummy;

}
int main (const int argc, const char **argv)
{
    const char *url = argv[1];
    Server server(url);
    while(1)
    {
        server.receive(dummy);
        // server.send((const char*)(&greeting), sizeof(greeting));
    }
}