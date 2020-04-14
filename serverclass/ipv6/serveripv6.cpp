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
#include "serveripv6.h"
#include <string>

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#define BACKLOG 5

#define BUFFER_SIZE 1024
using namespace std;


void Serveripv6Class::InitializeSocketipv6() {


    //socket
    int serverSocket = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == -1) {
        cout << "fail" << endl;
    } else {
        cout << "socket works" << endl;
    }

    //bind
    sockaddr_in6 server;
    server.sin6_family = AF_INET6;
    server.sin6_flowinfo = 0;
    server.sin6_port = htons(4801);
    server.sin6_scope_id = 0;
    server.sin6_addr = IN6ADDR_ANY_INIT;

    if (bind(serverSocket, (sockaddr *) &server, sizeof(server)) == -1) {
        cout << "bind fail" << endl;
    } else {
        cout << "bind works" << endl;
    }

    //listen
    int rVal = listen(serverSocket, BACKLOG);
    if (rVal == -1) {
        cout << "fail listening" << endl;
    } else {
        cout << "listening works" << endl;
    }

    //accept
    sockaddr_in6 clientAddr;
    int size = sizeof(clientAddr);
    int client = accept(serverSocket,
                        (struct sockaddr *) &clientAddr,
                        &size);
    if (client == -1) {
        cout << "fail accept" << endl;

    } else {
        cout << "accept working" << endl;
    }


    int p = 0;
    while (p == 0) {

        //recieve
        char msg[BUFFER_SIZE];
        int rcVal = recv(client, msg, BUFFER_SIZE, 0);
        if (rcVal == -1) {
            cout << "recieve error" << endl;
        } else if (rcVal == 0) {
            p=1;
            close(client);
            cout << "communication interruption" << endl;
        } else {
            cout << msg << endl;
        }

        //send
        int msgSize = strlen(msg); // check size!

        if(strncmp(msg, "getSensortypes()", 14)==0){
            int sendVal = send(client, "light;noise;air#", msgSize, 0);
        }else if(strncmp(msg, "Sensor(air)#", 6) ==0){
            srand (time(NULL));
            string msgString= "|"+ std::to_string(rand() % 255 + 100)+";"+
                              std::to_string(rand() % 255 + 100) +";" + std::to_string(rand() % 255 + 100)+ "#";


            strcpy(msg, msgString.c_str());

            int sendVal = send(client, msg, msgSize, 0);
        }else if(strncmp(msg, "getAllSensors()", 13) ==0){
            string msgString= "|air; "+ std::to_string(rand() % 255 + 100)+"| light; "+
                              std::to_string(rand() % 255 + 100) + "| noise; " + std::to_string(rand() % 255 + 100)+ "#";


            strcpy(msg, msgString.c_str());

            int sendVal = send(client, msg, msgSize, 0);
        }else if(strcmp(msg, "close") ==0){
            p=1;
            close(client);
        }else{

            int sendVal = send(client, "no matching sensors", msgSize, 0);
        }


    }


}





    Serveripv6Class::Serveripv6Class() {

    }
    Serveripv6Class::~Serveripv6Class() {

    }


    #endif