#include<iostream>
#include<unistd.h> //system call for read,write,close
#include<fcntl.h> //contains constants and flags for file operations (O_RDONLY, O_WRONLY, O_CREAT)
using namespace std;

int main(){
    int source = open("input.txt",O_RDONLY);
    int dest = open("output.txt", O_WRONLY | O_CREAT, 0644); 

    char buffer[100];
    int n;

    while((n = read(source,buffer,sizeof(buffer)))>0){
        write(dest,buffer,n);
    }

    close(source);
    close(dest);
    return 0;
}