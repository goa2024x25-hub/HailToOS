# include<iostream>
using namespace std;

int main(){
    int num_process;
    cout<<"number of process: ";
    cin>>num_process;

    int burst[num_process], wait[num_process], TAT[num_process];

    for (int i=0 ; i<num_process ; i++){
        cout<<"Burst time for process: "<<i+1<<":";
        cin>>burst[i];
    }
    cout<<"\n";

    wait[0]=0; // it means first process doesn't wait.
    for(int i=1;i<num_process;i++){
        wait[i] = wait[i-1] + burst[i-1];
    }

    for(int i=0; i<num_process;i++){
        TAT[i] = wait[i] + burst[i];
    }
    cout<<"\nProcess Burst Wait   TAT\n";

    for(int i=0;i<num_process;i++){
        cout<<i+1<<"\t"<<burst[i]<<"\t"<<wait[i]<<"\t"<<TAT[i]<<"\n";
    }
    return 0;
}
