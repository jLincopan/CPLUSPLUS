#include "udpClient.h"

int enviarUDP(char ip[], unsigned short int SERVER_PORT, char mensaje[]) {
 int sockfd; /* descriptor a usar con el socket */
 struct sockaddr_in their_addr; /* almacenara la direccion IP y numero de puerto del servidor */
 struct hostent *he; /* para obtener nombre del host */
 int numbytes; /* conteo de bytes a escribir */

 /* convertimos el hostname a su direccion IP */
 if ((he=gethostbyname(ip)) == NULL) {
 herror("gethostbyname");
 exit(1);
 }

 /* Creamos el socket */
 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
 perror("socket");
 exit(1);
 }

 /* a donde mandar */
 their_addr.sin_family = AF_INET; /* usa host byte order */
 their_addr.sin_port = htons(SERVER_PORT); /* usa network byte order */
 their_addr.sin_addr = *((struct in_addr *)he->h_addr);
 bzero(&(their_addr.sin_zero), 8); /* pone en cero el resto */

 /* enviamos el mensaje */
 if ((numbytes=sendto(sockfd,mensaje,strlen(mensaje),0,(struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
 perror("sendto");
 exit(1);
 }

 printf("enviados %d bytes hacia %s\n",numbytes,inet_ntoa(their_addr.sin_addr));

 /* cierro socket */
 close(sockfd);

 return 0;
}
