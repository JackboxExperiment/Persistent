#include "pipe_networking.h"

void signal_handler(int signo) {
  if (signo == SIGINT) {
    remove("wkp");
    exit(0);
  }
}

int main() {
  signal(SIGINT, signal_handler);
  
  int to_client;
  int from_client;
  char data[BUFFER_SIZE];

  
  while (1) {
    from_client = server_handshake( &to_client );

    while (1) {
      printf("client input: %s\n", data);

      char message[BUFFER_SIZE];
      int i = read(from_client, message, BUFFER_SIZE);

      if (!i) {
	break;
      }
      
      int j = 0;
      while(message[j]) {
	message[j] += 3;
	j++;
      }
      
      write(to_client, message, BUFFER_SIZE);
    }
  }
}  
