#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
    pid_t pid=fork();

    if(pid==0){
        execl("/bin/ls","ls",NULL);
    }

    else{
        wait(NULL);
        cout<<"Child Finished. Parent  exist. \n ";
    }

    return 0;
}
