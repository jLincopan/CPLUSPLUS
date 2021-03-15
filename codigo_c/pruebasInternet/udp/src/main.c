#include "udpServer.h"
#include "udpClient.h"

int main() {
  recibirUDP(60000);
  enviarUDP("192.168.0.100", 60000, "hola");
  return 0;
}
