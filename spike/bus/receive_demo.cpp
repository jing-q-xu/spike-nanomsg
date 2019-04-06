#include <iostream>
#include <unistd.h>
#include "node.h"
#include "msg.h"
#include "actor.h"
#include "data_mother.h"
namespace
{
DummyActor dummy;
}
int main (const int argc, const char **argv)
{
    if(argc < 3)
    {
        std::cout << "usage: receive local remote [remote ...]" << std::endl;
    }
    Greeting greeting;
    Node node;
    node.init(argv[1]);
    for (int i = 2; i < argc; i++)
    {
        node.connect(argv[i]);
    }

    while(1)
    {
        node.receive(dummy);
    }
    return 0;
}