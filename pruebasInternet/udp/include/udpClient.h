#ifndef _UDP_CLIENT_
#define _UDP_CLIENT_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>


int enviarUDP(char ip[],unsigned short int SERVER_PORT, char mensaje[]);

 #endif
