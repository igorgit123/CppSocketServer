#include <iostream> // cout, cin
#include <sys/socket.h> // socket, bind, listen, accept
#include <netinet/in.h> // IPPROTO_TCP, sockaddr_in,
// htons/ntohs, INADDR_ANY
#include <unistd.h> // close
#include <arpa/inet.h> // inet_ntop/inet_atop
#include <string.h> // strlen
#include <semaphore.h> // sem_init


#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#define BUFFER_SIZE 1024
using namespace std;

#endif

int main() {

    //socket
    int udpSocket = socket(AF_INET, SOCK_DGRAM, 0);

    //sent to
    char* msg = "Hello udp";
    int msgSize = strlen(msg); // check size!
    sockaddr_in toAddr;
    toAddr.sin_family = AF_INET;
    toAddr.sin_port = htons(4980);
    toAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(toAddr.sin_zero),'\0',8);
    int toSize = sizeof(toAddr);
    int res = sendto(udpSocket,
                     msg,
                     msgSize,
                     0,
                     (sockaddr*)&toAddr,
                     toSize);
    if(res==-1){
        cout<< "Send failed"<<endl;
    }else{
        cout<< "Send succesful"<<endl;
    }

    //recieve from
    char msgrec[BUFFER_SIZE];
    sockaddr_in from;
    int fromSize = sizeof(from);
    int rVal = recvfrom(udpSocket, msgrec,
                        BUFFER_SIZE,
                        0,
                        (sockaddr*)&from,
                        &fromSize);
    if(rVal==-1){
        cout<< "recieve error"<< endl;
    }else{
        cout<< msgrec <<endl;
    }

}