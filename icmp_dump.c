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
    

    //store icmp packets to recvbuf
    r=recvfrom(sock,recvbuf,sizeof(recvbuf),0,&sender,&size);
    if(r==-1){
        perror("recvfrom error");
        return;
    }


    //converting the bytes in recev to meaningful output
    struct icmp *icmp;
    icmp = (struct icmp *)(recvbuf+20);                           //i think first 20 byte is ip header so +20




}

int main(){
    int rawsock;


    //create rawsocket that listens to icmp packets
    if((rawsock=socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))==-1){
                perror("socket error ");
                return -1;
        }


}
