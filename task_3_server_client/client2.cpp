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
    //string buff,result;
    //string buffer;
    // a = sizeof(buffer);
    // b= sizeof(buff);

    /*if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }*/
    portno = PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    else cout<<"Socket opened"<<endl;
    server = gethostbyname("localhost");
    /*if (server == NULL) {
        cout<<"ERROR, no such host"<<endl;
        exit(0);
    }*/
    ifstream inf("input.txt");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    else cout<<"Connected"<<endl;
   while(inf){
        	/*std::string strInput;*/
        inf>>buffer;
       // cout<<buffer;
        //buffer[1]=" ";
        //buffer[2]='\0';
/*    bzero(buffer,256);
    fgets(buffer,255,);*/

        cout<<buffer<<endl;//<<buffer.length();
        a+=digit(buffer);
        cout<<"sending "<<buffer;
    	n = send(sockfd,buffer,4,0);
        b+=n;
    	if (n < 0) 
    	     error("ERROR writing to socket");
    	 else cout<<"Wrote to socket"<<endl;   
    	//bzero(buffer,a)
     }
    	//m = read(sockfd,(char*)&buff,buff.length());
    cout<<"a = "<<a<<"b = "<<b<<endl;
    a-=2;
    b=((b/4)-2);
    b=(b*2)+(b-1)*2+2;
    a+=b;
    cout<<"new a = "<<a<<endl;
   // cout<<"new a = "<<a<<endl;
   // m = read(sockfd,(char*)&buff,a);
    m = read(sockfd,buff,a);
    if (m < 0) 
     	error("ERROR reading from socket");
    else cout<<"Reading from socket"<<endl;
   	cout<<"Printing from buffer"<<endl;
    cout<<"m="<<m<<endl;
   // cout<<1234567<<endl;
        //cout<<"Result is "<<result<<endl;
        cout<<"buff len = "<<strlen(buff)<<endl;
        //buff[strlen(buff)]='\0';
        cout<<buff<<endl;
        /*for(int z=0;z<strlen(buff);z++){
            cout<<buff[z];
        }*/
 	//}
	 //close(sockfd);
	cout<<"Connection closed"<<endl;  //*/}
    return 0;
}