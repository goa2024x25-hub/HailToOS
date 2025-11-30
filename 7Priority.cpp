#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"total process:";
    cin>>n;

    int burst[n],priority[n],process[n];
    for(int i=0;i<n;i++){
        process[i]=i+1;
        cout<<"burst time of "<<i+1<<":";
        cin>>burst[i];
        cout<<"Priority of "<<i+1<<":";
        cin>>priority[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(priority[j]>priority[i]){
                swap(priority[i],priority[j]);
                swap(burst[i],burst[j]);
                swap(process[i],process[j]);
            }
        }
    }    


    int wait[n],TAT[n];
    wait[0]=0;
    for(int i=1;i<n;i++){
        wait[i] = wait[i-1] + burst[i-1]; 
    }

    for(int i=0;i<n;i++){
        TAT[i]=wait[i] + burst[i];
    }

    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<process[i]<<"\t"<<burst[i]<<"\t"<<priority[i]<<"\t"<<wait[i]<<"\t"<<TAT[i]<<"\n";
    }

    return 0;
}