#include <iostream>
#include <stdio.h>
#include <string.h>
#include <signal.h>

using namespace std;


int main(int argc, char** argv) {

    if(argc!=4){
        cout << "usage: client <server_pid> <SIGNAL> <number of signals to send>" << endl;
        cout << "where SIGNAL is one of: 2 (this is for SIGINT)  or   10 (this is for SIGUSR1)" << endl; 
        cout << "Exiting..." << endl;
        return 1;
    } 

    int serverPid = atoi(argv[1]);
    int numberOfSignalsToSend = atoi(argv[3]);

    for (int i=0; i<numberOfSignalsToSend; i++)
    {
        if (strcmp(argv[2],"2")==0)
        {
            kill(serverPid, SIGINT);
        }
        else if (strcmp(argv[2],"10")==0)
        {
            kill(serverPid, SIGUSR1);
        }
    }    
}