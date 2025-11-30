#include<iostream>
#include<pthread.h>
using namespace std;

int numbers[100];
int sum = 0;

void* calculate(void* n_ptr){
    int n= *(int*)n_ptr;
    for(int i=0;i<n;i++){
        sum += numbers[i];
    }

    return NULL;
}

int main(){
    int n;
    cout<<"Total Elements: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    pthread_t thread;
    pthread_create(&thread, NULL, calculate, &n);
    pthread_join(thread, NULL);

    cout<<"Sum = "<<sum<<endl;
    return 0;
}