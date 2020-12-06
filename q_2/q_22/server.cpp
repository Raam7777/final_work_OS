#include <iostream>
#include <stdio.h>
#include <string.h>
#include <signal.h>

using namespace std;
int count_sigint_signals=0;
void signal_handler_for_sigint(int sig) {
    cout << "SIGINT signal received." << endl;
    count_sigint_signals++;
    signal(sig, signal_handler_for_sigint);
}

void signal_handler_for_sigusr1(int sig) {
    cout << "SIGUSR1 signal received." << endl;
    cout << count_sigint_signals <<endl;
    signal(sig, signal_handler_for_sigusr1);
}

int main(int argc, char** argv) {

    cout << "Server starts." << endl;

    //Register handler (callback function) for the signal SIGINT
    signal(SIGINT, signal_handler_for_sigint);    

    //Register handler (callback function) for the signal SIGUSR1
    signal(SIGUSR1, signal_handler_for_sigusr1);    

    cout << "Server waits for signals..." << endl; 
    while (1);

    cout << "Exiting..." << endl;
}