#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    pid_t pid= fork();

    if (pid==0){
        cout<<"child code"<<"\n";
    }

    else{
        cout<<"parent code"<<"\n";
    }

    return 0;
}