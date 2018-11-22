#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 1234

using std::cerr;
using std::endl;

int main ()
{
  // file descriptor for socket
  int sockfd;
  int client_sockfd;

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

  /* 
   * // Internet address
   * struct in_addr 
   * {
   *     // in_addr_t is typedef of unsinged int
   *     in_addr_t s_addr;
   * };
   * 
   * 
   */
  struct sockaddr_in addr;

  socklen_t len = sizeof ( struct sockaddr_in);
  struct sockaddr_in from_addr;

  char buf[BUFFER_SIZE];

  // initialize the buffer
  memset (buf, 0, sizeof ( buf));

  /*
   * generate socket
   * socket(int domain, int type, int protocol);
   * domain:socket domain
   * type:socket type. SOCK_STREAM(TCP/IP) or SOCK_DGRAM(UDP/IP)
   */
  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
      // if failed to generate socket, socket func returns negative value.
      cerr << "socket Error" << endl;
    }

  // setting for IP address and port
  addr.sin_family = AF_INET; // IPv4
  addr.sin_port = htons (PORT_NUMBER); // convert to network bytes order
  addr.sin_addr.s_addr = INADDR_ANY; // Any address

  // bind
  // bind(int, const struct sockaddr *, socklen_t)
  if (bind (sockfd, (struct sockaddr *) &addr, sizeof ( addr)) < 0)
    {
      // if failed to bind, bind func returns negative value.
      cerr << "bind Error" << endl;
    }

  // listen
  /*
   * int listen(int sockfd, int backlog);
   * 
   * backlog is Maximum queue length specifiable by listen.
   */
  if (listen (sockfd, SOMAXCONN) < 0)
    {
      // if failed to listen, listen func returns negative value.
      cerr << "listen Error" << endl;
    }

  // accept
  /*
   * int accept(int socket, struct sockaddr *address, int *address_len);
   * socket is sockfd
   * address is socket address of connecting client. written by accept func.
   * address_len is size of address
   */
  if ((client_sockfd = accept (sockfd, (struct sockaddr *) &from_addr, &len)) < 0)
    {
      cerr << "accept" << endl;
    }

  // recieve
  int recv_size;
  while (1)
    {
      /*
       * ssize_t recv(int sockfd, void *buf, size_t len, int flags);
       * return bytes num of recieved data
       */
      recv_size = recv (client_sockfd, buf, sizeof (buf), 0);

      if (recv_size == 0)
        {
          // Normal End Connection.
          break;
        }
      else if (recv_size == -1)
        {
          cerr << "recv Error" << endl;
        }
      else
        {
          cerr << "receive:" << buf << endl;
          sleep (1);

          // send message
          cerr << "send:" << buf << endl;
          write (client_sockfd, buf, recv_size);
        }
    }

  // close socket
  close (client_sockfd);
  close (sockfd);

  return 0;
}
