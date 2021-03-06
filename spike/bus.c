#include <assert.h>
#include <libc.h>
#include <stdio.h>
#include <nanomsg/nn.h>
#include <nanomsg/bus.h>

int node(const int argc, const char **argv)
{
    int bind_sock = nn_socket(AF_SP, NN_BUS);
    int connect_sock = nn_socket(AF_SP, NN_BUS);
    assert(bind_sock >= 0);
    assert(connect_sock >= 0);
    assert(nn_bind(bind_sock, argv[2]) >= 0);
    sleep(1); // wait for connections
    if (argc >= 3)
    {
        for (int x = 3; x < argc; x++) {
            assert(nn_connect(connect_sock, argv[x]) >= 0);
        }
    }
    sleep(1); // wait for connections
    int to = 100;
    assert(nn_setsockopt(bind_sock, NN_SOL_SOCKET, NN_RCVTIMEO, &to, sizeof(to)) >= 0);
    // SEND
    int sz_n = strlen(argv[1]) + 1; // '\0' too
    printf("%s: SENDING '%s' ONTO BUS\n", argv[1], argv[1]);
    int send = nn_send(connect_sock, argv[1], sz_n, 0);
    assert(send == sz_n);
    while (1)
    {
        // RECV
        char *buf = NULL;
        int recv = nn_recv(bind_sock, &buf, NN_MSG, 0);
        if (recv >= 0)
        {
            printf("%s: RECEIVED '%s' FROM BUS\n", argv[1], buf);
            nn_freemsg(buf);
        }
    }
    nn_shutdown(bind_sock, 0);
    return nn_shutdown(connect_sock, 0);
}

int main(const int argc, const char **argv)
{
    if (argc >= 3)
        node(argc, argv);
    else
    {
        fprintf(stderr, "Usage: bus <NODE_NAME> <URL> <URL> ...\n");
        return 1;
    }
}
