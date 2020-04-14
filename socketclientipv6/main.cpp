//
// Created by Igor on 14.11.2019.
//
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

int main(int _argc, char** _argv) {

    //socket
    int clientSocket = socket(AF_INET6, SOCK_STREAM, 0);
    if(clientSocket==-1){
        cout<< "socket doesnt work" <<endl;

    }else{
        cout<<"socket works" << endl;
    }

    //connect
    sockaddr_in6 server_address;
    server_address.sin6_family = AF_INET6;
    server_address.sin6_flowinfo = 0;
    server_address.sin6_port = htons(4801);
    server_address.sin6_scope_id = 0;
    int res = inet_pton(AF_INET6,
                        "::1", // or "fe80::fd60:3f7a:c5b:c9dd"
                        &(server_address.sin6_addr));



    int rVal = connect(clientSocket, (sockaddr*)&server_address, sizeof(server_address));
    if(rVal == -1){
        cout<< "connect failed" <<endl;
    }else{
        cout<< "connecting works" <<endl;

    }

    int p=0;
    while(p==0) {

        cout << "Choose a command:\n"
                "-----------------------------\n"
                "1. getSensortypes()#\n"
                "2. Sensor(air)#\n"
                "3. Sensor(noise)#\n"
                "4. Sensor(light)#\n"
                "5. getAllSensors()#\n"
                "6. Close communication\n";
        int command;
        cin >> command;
        char *msge;
        switch (command) {
            case 1:
                msge = "getSensortypes()";
                break;
            case 2:
                msge = "Sensor(air)";
                break;
            case 3:
                msge = "Sensor(noise)";
                break;
            case 4:
                msge = "Sensor(light)";
                break;
            case 5:
                msge = "getAllSensors()";
                break;
            case 6:
                close(clientSocket);
                p = 1;
                break;
            default:
                cout << "choose a valid command";
                break;
        }



        //send


        int msgSize = strlen(msge); // check size!
        int sendVal = send(clientSocket, msge, msgSize, 0);


        //recieve
        char msg[BUFFER_SIZE];
        int rcVal = recv(clientSocket, msg, BUFFER_SIZE, 0);

        if (rcVal == -1) {
            cout << "recieve error" << endl;

        } else if (rcVal == 0) {
            cout << "communication interruption" << endl;
        } else {
            cout << msg << endl;
        }




    }
}
#endif