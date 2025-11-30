


#include<iostream>
#include<unistd.h> //-> contains fork() and getpid() system calls.
using namespace std;

int main(){
    pid_t pid = fork(); //->creates a new process

    if (pid<0){
        cout<<"fork failed";
    }
    else if (pid==0){
        cout<<"child process.  PID = "<<getpid()<<"\n";
    }
    else{
        cout<<"Parent process. PID = "<<getpid()<<"\n";
    }

    return 0;
}