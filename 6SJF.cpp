#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Total process: ";
    cin>>n;

    int burst[n],process[n];

    for(int i=0;i<n;i++){
        process[i]=i+1;
        cout<<"burst time for "<<i+1<<":";
        cin>>burst[i];
    }

    for (int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(burst[j]<burst[i]){
                swap(burst[i],burst[j]);
                swap(process[i],process[j]);
            }
        }
    }

    int wait[n],TAT[n];
    wait[0]=0;
    for(int i=0;i<n;i++){
        wait[i]=wait[i-1]+burst[i-1];
    }

    for (int i=0;i<n;i++){
        TAT[i]=wait[i]+burst[i];
    }

    cout<<"Process"<<"\t"<<"burst"<<"\t"<<"wait"<<"\t"<<"TAT"<<"\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<burst[i]<<"\t"<<wait[i]<<"\t"<<TAT[i]<<"\n";
    }
    return 0;
}