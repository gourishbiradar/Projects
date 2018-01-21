#include <sys/types.h> // to use type of network family and protocols
#include <sys/socket.h> // to use socket functions


/*
******
int socket(int family, int type, int protocol);
*returns the socket file descriptor on success and -1 on failure
!!family:
AF_INET-->IPv4
AF_INET6-->IPv6
AF_LOCAL-->Unix domain protocols
AF_ROUTE-->Routing sockets
AF_KEY-->ket sockets (?!!)

!!type:
SOCK_STREAM -->streaming socket, sends data in order and ensures it's delivery
SOCK_DGRAM --> datagram socket, sends data maybe in order and does not ensure it's delivery
SOCK_SEQPACKET -->sequenced packet socket, sends data in order and does not ensure it's delivery
SOCK_RAW --> raw socket(maybe future use, i am not sure!!)

!!protocol:
set to 0 if you want to use system default
IPPROTO_TCP --> TCP
IPPROTO_UDP --> UDP
IPPROTO_SCTP --> SCTP (duh!)
*/

/*
******
int connect(int sockfd, struct sockaddr *serv_addr, int addr_len);
*used by tcp client to establish a connection with a tcp server
*returns 0 on success and -1 otherwise

!!sockfd: the value returned by socket()
!!serv_addr: the pointer to sockaddr which stores the destination IP addr and port
!!addr_len: the length of destination addr, i.e. sizeof(struct sockaddr)
*/

/*
******
int bind(int sockfd, struct sockaddr *my_addr, int addr_len);
*binds the ipv4(32 bit)/ipv6(128 bit) address to 32 bit tcp or udp port on the system
*returns 0 on success and -1 otherwise

!!sockfd: socket file descriptor retunred by socket()
!!my_addr: a pointer to struct sockaddr which has system ip addr and port
** my_addr.sin_port = 0; --> to let the system choose some random port
** my_addr.sin_addr.s_addr = INADDR_ANY; -->ip address is assinged automatically
!!addrlen: the length of sockaddr i.e. sizeof(struct sockaddr)

ports below 1024 are reserverd!!!
*/