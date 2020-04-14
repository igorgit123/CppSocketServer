#include <iostream>
#include <sys/socket.h> // socket, bind, listen, accept
#include <netinet/in.h> // IPPROTO_TCP, sockaddr_in,
// htons/ntohs, INADDR_ANY
#include <unistd.h> // close
#include <arpa/inet.h> // inet_ntop/inet_atop
#include <string.h> // strlen
#include <semaphore.h> // sem_init
#include "serveripv4.h"
#include <string>

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#define BACKLOG 5

#define BUFFER_SIZE 1024
using namespace std;

/*
    cout<< _argc<<endl;
    for(int i=0; i<_argc; i++){
        cout << i<< " "<< _argv[i]<<endl;

        int p;
        p= atoi(_argv[1]);
        cout<<p;
    }

*/

void Serveripv4Class::InitializeSocketipv4() {

    //socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == -1) {
        cout << "fail" << endl;
    } else {
        cout << "socket works" << endl;
    }

    //bind
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4977);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(serverAddr.sin_zero), '\0', 8);
    if (bind(serverSocket, (sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        cout << "bind fail" << endl;
        return;
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

    while (true) {


        //accept
        sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);
        int commSocket = accept(serverSocket,
                                (sockaddr *) &clientAddr,
                                &clientAddrSize);
        if (commSocket == -1) {
            cout << "fail accepting" << endl;

        } else {
            cout << "accept working" << endl;
        }
        cout << "print random" << endl;
        char ip[INET_ADDRSTRLEN];

        inet_ntop(AF_INET, &clientAddr.sin_addr, ip, INET_ADDRSTRLEN);
        cout << "client ip adress: " << ip << endl;



        //recieve




        int p = 0;
        while (p == 0) {


            char msg[BUFFER_SIZE];
            memset(msg, '\0', BUFFER_SIZE);
            int rcVal = recv(commSocket, msg, BUFFER_SIZE, 0);
            if (rcVal == -1) {
                cout << "recieve error" << endl;
                break;
            } else if (rcVal == 0) {
                p = 1;
                close(commSocket);
                cout << "communication interruption" << endl;
                break;
            } else {
                cout << msg << endl;
            }

            //send
            int msgSize = strlen(msg); // check size!

            if (strncmp(msg, "getSensortypes()", 14) == 0) {

                int sendVal = send(commSocket, "light;noise;air#", msgSize, 0);
                if (sendVal <= 0) {
                    cout << "client disconnected" << endl;
                    break;
                }

            } else if (strncmp(msg, "Sensor(air)#", 5) == 0) {


                srand(time(NULL));

                string msgString = std::to_string(rand() % 255 + 100) + ";" +
                                   std::to_string(rand() % 255 + 100) + ";" + std::to_string(rand() % 255 + 100) +
                                   "#";


                //strcpy(msg, msgString.c_str());
                //  msgString.append("\n");
                cout << msgString << endl;
                int sendVal = send(commSocket, msgString.c_str(), msgString.size(), 0);
                if (sendVal <= 0) {
                    cout << "client disconnected" << endl;
                    break;
                }

            } else if (strncmp(msg, "getAllSensors()", 13) == 0) {

                string msgString = "|air;" + std::to_string(rand() % 255 + 100) + "|light;" +
                                   std::to_string(rand() % 255 + 100) + "|noise;" +
                                   std::to_string(rand() % 255 + 100) + "#";


                // strcpy(msg, msgString.c_str());

                cout << msgString << endl;
                int sendVal = send(commSocket, msgString.c_str(), msgString.size(), 0);
                if (sendVal <= 0) {
                    cout << "client disconnected" << endl;
                    break;
                }
            } else if (strcmp(msg, "close") == 0) {

                close(commSocket);
                break;
            } else {

                int sendVal = send(commSocket, "no matching sensors", msgSize, 0);
            }


        }
    }
}

Serveripv4Class::Serveripv4Class() {

}

Serveripv4Class::~Serveripv4Class() {}


#endif