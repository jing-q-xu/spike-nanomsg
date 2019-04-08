#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include "node.h"
#include "data_mother.h"
#include "msg.h"

namespace
{
    Node node;
}
    
void * send_msg(void * args)
{
    Greeting greeting;
    while(1)
    {
        node.send((const char*)(&greeting), sizeof(greeting));
        usleep(10);
        greeting.count++;
        if (greeting.count % 10000 == 0)
        {
            std::cout << "send count: " << greeting.count << std::endl;
        }
    }
}

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        std::cout << "usage: " << argv[0] << "local remote " << std::endl;
    }

    node.init(argv[1]);
    node.connect(argv[2]);

    pthread_t transmitter;
    int ret = pthread_create(&transmitter, NULL, send_msg, NULL);
    if(ret != 0)
    {
        std::cout << "failed to create transmit thread" << std::endl;
        return -1;
    }
    DummyActor dummy;
    while(1)
    {
        if (node.receive(dummy) != 0)
        {
            break;
        }
    }
    pthread_cancel(transmitter);
    pthread_join(transmitter, NULL);
    return 0;

}
