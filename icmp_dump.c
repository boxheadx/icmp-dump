#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>


void recv_icmp(int sock){
    char recvbuf[1024];
    
    // to store sender's info 
    struct sockaddr *sender=malloc(sizeof(struct sockaddr));
    socklen_t size=sizeof(sender);

    //store icmp packets to recvbuf
    int r=recvfrom(sock,recvbuf,sizeof(recvbuf),0,sender,&size);
    if(r==-1){
        perror("recvfrom error");
        return;
    }

    //extracting sender's ip from sender struct and printing it
    struct sockaddr_in* s = (struct sockaddr_in*)sender;
    printf("%s\n", inet_ntoa(s->sin_addr));

}

int main(){
    int rawsock;


    //create rawsocket that listens to icmp packets
    if((rawsock=socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))==-1){
                perror("socket error ");
                return -1;
    }


    for(;;){
    	recv_icmp(rawsock);
	}

}
