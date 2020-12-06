/**
 * This is a "hello world" program for the C++ course.
 */

#include <iostream>
#include <string>
#include <signal.h>

using namespace std;




int main(int argc, char** argv) { 
    
    

    if(argc!=2){
        cout << "usage: check_pid <pid> \n Exiting...\n";
        return 1;
    } 

//    cout << "Received PID is: " << argv[1];

    int pid = atoi(argv[1]);

//   cout << "Sending kill to pid " << pid << "\n";
    int status = kill (pid, 0);

    if (status==0)
    {
        cout << "Process " << pid << " exists." << endl;
    }
    else if (status<0)
    {
        if (errno == EPERM)
        {
            cout << "Process " << pid << " exists but we have no permission."<<endl;
        }
        else if (errno==ESRCH)
        {
            cout << "Process " << pid << " does not exist."<<endl;
        }
    }

    return 0; 
}
