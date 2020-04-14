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
    /*  cout<< _argc<<endl;
      for(int i=0; i<_argc; i++){
          cout << i<< " "<< _argv[i]<<endl;
          } */

      //socket
      int commSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if(commSocket==-1){
          cout<< "socket doesnt work" <<endl;

      }else{
          cout<<"socket works" << endl;
      }

      //connect
      sockaddr_in serverAddr;
      serverAddr.sin_family = AF_INET;
      serverAddr.sin_port = htons(atoi(_argv[1]));
      serverAddr.sin_addr.s_addr = inet_addr(_argv[2]);
      memset(&(serverAddr.sin_zero),'\0',8);


      int rVal = connect(commSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
      if(rVal == -1){
          cout<< "connect failed" <<endl;
      }else{
          cout<< "connecting works" <<endl;

      }
        int p=0;
    while(p==0){

          cout << "Choose a command:\n"
                  "-----------------------------\n"
                  "1. getSensortypes()#\n"
                  "2. Sensor(air)#\n"
                  "3. Sensor(noise)#\n"
                  "4. Sensor(light)#\n"
                  "5. getAllSensors()#\n"
                  "6. Close communication\n";
          int command;
        cin>>  command;
        char* msge;
        switch(command){
            case 1: msge = "getSensortypes()";
                break;
            case 2: msge = "Sensor(air)";
                break;
            case 3: msge = "Sensor(noise)";
                break;
            case 4: msge = "Sensor(light)";
                break;
            case 5: msge = "getAllSensors()";
                break;
            case 6:     close(commSocket);
                        p=1;
                break;
            default: cout<< "choose a valid command";
                break;
        }

      //send

      int msgSize = strlen(msge); // check size!
      int sendVal = send(commSocket, msge, msgSize, 0);

      //recieve
      char msg[BUFFER_SIZE];
      int rcVal = recv(commSocket, msg, BUFFER_SIZE, 0);

      if(rcVal==-1){
          cout<< "recieve error"<< endl;

      }else if(rcVal==0){
          cout<< "communication interruption" << endl;
      }else{
          cout<< msg <<endl;
      }




}
}
#endif