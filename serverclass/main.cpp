//
// Created by Igor on 14.11.2019.
//
#include <iostream>
#include "ipv4/serveripv4.h"
#include "ipv6/serveripv6.h"
#include "udp/serverudp.h"
using namespace std;


int main(int _argc, char **_argv) {
    Serveripv4Class serveripv4;
    Serveripv6Class serveripv6;
    ServerUdp serverudp;
    cout << "C++ Server Menu:\n"
            "-----------------------------\n"
            "1. Start TCP v4 Server\n"
            "2. Start TCP v6 Server\n"
            "3. Start UDP Echo Server\n"
            "4. EXIT\n"
            "-----------------------------\n"
            "Choose server type to start:";

    int p;
    cin >> p;


    switch(p){
        case 1: serveripv4.InitializeSocketipv4();
            break;
        case 2: serveripv6.InitializeSocketipv6();
            break;
        case 3: serverudp.InitializeSocketUdp();
            break;

        case 4: cout<< "Finished." << endl;
            break;

        default: cout<< "Pick one of the listed options."<< endl;
            break;
    }

}