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

    // Sort by arrival time
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(at[j] < at[i]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;

    for(int i=1;i<n;i++) {
        wt[i] = (at[i-1] + bt[i-1] + wt[i-1]) - at[i];
        if(wt[i] < 0) wt[i] = 0;
    }

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] 
             << "\t" << wt[i] << "\t" << tat[i] << "\n";

    return 0;
}
