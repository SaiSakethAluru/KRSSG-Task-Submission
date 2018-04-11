#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <fstream>
using namespace std;
#define PORT 8081
int digit(string temp){
    return temp.length();
}
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main()
{
    int sockfd, portno, n,a=0,b=0,m;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[4],buff[1024]; 
    portno = PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    else cout<<"Socket opened"<<endl;
    server = gethostbyname("localhost");
    ifstream inf("input.txt");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    else cout<<"Connected"<<endl;
   while(inf){
        inf>>buffer;    
        a+=digit(buffer);
    	n = send(sockfd,buffer,4,0);
        b+=n;
    	if (n < 0) 
    	     error("ERROR sending to server");  
     }
    a-=2;
    b=((b/4)-2);
    b=(b*2)+(b-1)*2+2;
    a+=b;
    m = read(sockfd,buff,a);
    if (m < 0) 
     	error("ERROR reading from socket");
    else cout<<"Reading data"<<endl;
   	cout<<"Printing data"<<endl;
        cout<<buff<<endl;
	cout<<"Connection closed"<<endl; 
    return 0;
}
