#ifndef T_NET_H_
#define T_NET_H_
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;
int socket_b(int port);
#endif
