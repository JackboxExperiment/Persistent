#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( & to_server );

  while (1) {
    printf("Enter data: ");
    char message[BUFFER_SIZE];
    fgets(message, BUFFER_SIZE, stdin);

    int i = 0;
    while(message[i]) {
      i++;
    }
    message[i-1] = 0;

    write(to_server, message, BUFFER_SIZE);
    read(from_server, message, BUFFER_SIZE);
    printf("Message: -%s-\n", message);
    
  }
}
