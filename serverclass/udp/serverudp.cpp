//
// Created by Igor on 14.11.2019.
//
#include <iostream>
#include <sys/socket.h> // socket, bind, listen, accept
#include <netinet/in.h> // IPPROTO_TCP, sockaddr_in,
// htons/ntohs, INADDR_ANY
#include <unistd.h> // close
#include <arpa/inet.h> // inet_ntop/inet_atop
#include <string.h> // strlen
#include <semaphore.h> // sem_init
#include "serverudp.h"
#include <string>

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#define BACKLOG 5

#define BUFFER_SIZE 1024
using namespace std;

#endif


void ServerUdp::InitializeSocketUdp() {
    //socket
   int udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(udpSocket == -1){
        cout << "socket fail" <<endl;
    }else{
        cout<<  "socket works" << endl;
    }
    //bind
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4980);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(serverAddr.sin_zero),'\0',8);
    if(bind(udpSocket, (sockaddr*) &serverAddr, sizeof(serverAddr))==-1){
        cout << "bind fail" <<endl;
    } else{
        cout << "bind works" <<endl;
    }


    //recieve from
    char msg[BUFFER_SIZE];
    sockaddr_in from;
    int fromSize = sizeof(from);
    int rVal = recvfrom(udpSocket, msg,
            BUFFER_SIZE,
            0,
            (sockaddr*)&from,
            &fromSize);
    if(rVal==-1){
        cout<< "recieve error"<< endl;
    }else{
        cout<< msg <<endl;
    }

    //sent to
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
                     (sockaddr*)&from,
                     sizeof(from));
    if(res==-1){
        cout<< "Send failed"<<endl;
    }else{
        cout<< "Send succesful"<<endl;
    }



}


ServerUdp::ServerUdp() {}
ServerUdp::~ServerUdp() {}

