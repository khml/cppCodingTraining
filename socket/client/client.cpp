#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 1234
#define ADDRESS  "127.0.0.1"
#define DATA_SIZE 10
#define CONNECT_TIMES 10

using std::cerr;
using std::endl;

int main ()
{
  int sockfd;
  struct sockaddr_in addr;

  /*
   * generate socket
   * socket(int domain, int type, int protocol);
   * domain:socket domain
   * type:socket type. SOCK_STREAM(TCP/IP) or SOCK_DGRAM(UDP/IP)
   */
  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
      cerr << "socket Error" << endl;
    }

  // Setting Address and port Number
  /*
   * struct sockaddr_in 
   * {
   *     __uint8_t	sin_len;
   *     sa_family_t	sin_family;  // address family
   *     in_port_t	sin_port;    // port
   *     struct	in_addr sin_addr;    // IP address
   *     char		sin_zero[8]; 
   * };
   */
  addr.sin_family = AF_INET;
  addr.sin_port = htons (PORT_NUMBER); // convert to network bytes order
  addr.sin_addr.s_addr = inet_addr (ADDRESS); // convert to network bytes order

  // Connecting to Server
  /*
   * int connect(int socket, const struct sockaddr *address, socklen_t address_len);
   * return 0 if normal end, -1 if not normal end.
   */
  connect (sockfd, (struct sockaddr *) &addr, sizeof ( struct sockaddr_in));

  // data sending
  char send_string[DATA_SIZE];
  char receive_string[DATA_SIZE];
  for (int i = 0; i < CONNECT_TIMES; i++)
    {
      sprintf (send_string, "%d", i);
      cerr << "send:" << i << endl;

      /*
       * ssize_t send(int socket, const void *buffer, size_t length, int flags);
       * return -1 if it has error, else int > 0
       * 
       * when flags = 0, send = write
       */
      if (send (sockfd, send_string, sizeof (send_string), 0) < 0)
        {
          cerr << "send" << endl;
        }
      else
        {
          /*
           * ssize_t recv(int sockfd, void *buf, size_t len, int flags);
           * return bytes num of recieved data
           * 
           * when flags = 0, revv = read
           */
          recv (sockfd, receive_string, sizeof (receive_string), 0);
          cerr << "receive:" << receive_string << endl;
        }
      sleep (1);
    }

  // close socket
  close (sockfd);

  return 0;
}