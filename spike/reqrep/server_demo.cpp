#include "server.h"
#include <iostream>
#include "msg.h"
#include "data_mother.h"

namespace
{
int count = -1;
DummyActor dummy;
}

int main (const int argc, const char **argv)
{
    const char *url = argv[1];
    Server server(url);
    while(1)
    {
        server.receive(dummy);
    }
}