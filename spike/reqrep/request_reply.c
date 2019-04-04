#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <libc.h>
#include <nanomsg/nn.h>
#include <nanomsg/reqrep.h>

#define NODE0 "node0"
#define NODE1 "node1"
#define DATE "DATE"

char *date ()
{
  time_t raw = time (&raw);
  struct tm *info = localtime (&raw);
  char *text = asctime (info);
  text[strlen(text)-1] = '\0'; // remove '\n'
  return text;
}

int node0 (const char *url)
{
  int sz_date = strlen (DATE) + 1; // '\0' too
  int sock = nn_socket (AF_SP, NN_REP);
  assert (sock >= 0);
  assert (nn_bind (sock, url) >= 0);
  while (1)
  {
    char *buf = NULL;
    int bytes = nn_recv (sock, &buf, NN_MSG, 0);
    static int count = 0;
    // assert (bytes >= 0);
    if (bytes < 0)
    {
      printf ("server: failed to RECEIVED DATE REQUEST");
      break;
    }
    count++;
    // if (strncmp (DATE, buf, sz_date) == 0)
    { 
      // if (count % 100 == 0) 
      {
        printf ("server: RECEIVED DATE REQUEST, buf=%s, count=%d\n", buf, count);
      }
      // char *d = date();
      // int sz_d = strlen(d) + 1; // '\0' too
      // printf ("server: SENDING DATE %s\n", d);
      // bytes = nn_send (sock, d, sz_d, 0);
      // assert (bytes == sz_d);
    }
    nn_freemsg (buf);
  }
  return nn_shutdown (sock, 0);
}

int node1 (const char *url)
{
  char greeting[128];
  char *buf = NULL;
  int sz_date = 0;
  int bytes = -1;
  int sock = nn_socket (AF_SP, NN_REQ);
  assert (sock >= 0);
  assert (nn_connect (sock, url) >= 0);
  printf ("client: SENDING DATE REQUEST %s\n", greeting);
  int to = 10;
  nn_setsockopt(sock, NN_SOL_SOCKET, NN_RCVTIMEO, &to, sizeof(to));
  nn_setsockopt(sock, NN_SOL_SOCKET, NN_REQ_RESEND_IVL, &to, sizeof(to));
  // for (int i = 0; i < 1000; i++)
  {
    snprintf(greeting, sizeof(greeting), "%s:%d", DATE, 1);
    sz_date = strlen(greeting) + 1; // '\0' too
    bytes = nn_send (sock, greeting, sz_date, 0);
    if (bytes != sz_date)
    {
      printf ("client: failed to send data, size: %d\n", bytes);
    }
    // sleep(1);
    // assert (bytes == sz_date);
    // bytes = nn_recv (sock, &buf, NN_MSG, 0);
    // assert (bytes >= 0);
    sleep(1000);
    // printf ("client: RECEIVED DATE %s\n", buf);
    // nn_freemsg (buf);
  }
  return nn_shutdown (sock, 0);
}

int main (const int argc, const char **argv)
{
  if (strncmp (NODE0, argv[1], strlen (NODE0)) == 0 && argc > 1)
    return node0 (argv[2]);
  else if (strncmp (NODE1, argv[1], strlen (NODE1)) == 0 && argc > 1)
    return node1 (argv[2]);
  else
    {
      fprintf (stderr, "Usage: reqrep %s|%s <URL> <ARG> ...\n",
               NODE0, NODE1);
      return 1;
    }
}
