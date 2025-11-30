#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Number of processes: ";
    cin >> n;

    int at[n], bt[n], wt[n], tat[n], p[n];

    for(int i=0;i<n;i++) {
        p[i] = i+1;
        cout << "Arrival time of P" << i+1 << ": ";
        cin >> at[i];
        cout << "Burst time of P" << i+1 << ": ";
        cin >> bt[i];
    }

    // Sort by arrival time first
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(at[j] < at[i]){
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    int completed = 0, time = 0, done[n] = {0};

    while(completed < n) {
        int idx = -1, mn = 1e9;

        for(int i=0;i<n;i++) {
            if(at[i] <= time && !done[i] && bt[i] < mn) {
                mn = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        wt[idx] = time - at[idx];
        time += bt[idx];
        tat[idx] = wt[idx] + bt[idx];
        done[idx] = 1;
        completed++;
    }

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] 
             << "\t" << wt[i] << "\t" << tat[i] << "\n";

    return 0;
}
