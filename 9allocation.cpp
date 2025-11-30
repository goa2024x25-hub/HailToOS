#include <iostream>
using namespace std;

int main() {
    int numBlocks, numProcesses;
    cout << "Enter number of memory blocks: ";
    cin >> numBlocks;
    cout << "Enter number of processes: ";
    cin >> numProcesses;

    int blockSize[numBlocks], processSize[numProcesses];

    cout << "Enter block sizes:\n";
    for(int i=0;i<numBlocks;i++) cin >> blockSize[i];

    cout << "Enter process sizes:\n";
    for(int i=0;i<numProcesses;i++) cin >> processSize[i];

    // ----------- FIRST FIT -----------
    int blockFF[numBlocks];
    for(int i=0;i<numBlocks;i++) blockFF[i]=blockSize[i];

    cout << "\nFirst-Fit Allocation:\n";
    for(int i=0;i<numProcesses;i++) {
        bool allocated = false;
        for(int j=0;j<numBlocks;j++) {
            if(blockFF[j]>=processSize[i]) {
                cout << "Process " << i+1 << " -> Block " << j+1 << "\n";
                blockFF[j]-=processSize[i];
                allocated = true;
                break;
            }
        }
        if(!allocated) cout << "Process " << i+1 << " -> Not allocated\n";
    }

    // ----------- BEST FIT -----------
    int blockBF[numBlocks];
    for(int i=0;i<numBlocks;i++) blockBF[i]=blockSize[i];

    cout << "\nBest-Fit Allocation:\n";
    for(int i=0;i<numProcesses;i++) {
        int bestIndex = -1;
        for(int j=0;j<numBlocks;j++) {
            if(blockBF[j]>=processSize[i]) {
                if(bestIndex==-1 || blockBF[j]<blockBF[bestIndex])
                    bestIndex = j;
            }
        }
        if(bestIndex!=-1) {
            cout << "Process " << i+1 << " -> Block " << bestIndex+1 << "\n";
            blockBF[bestIndex]-=processSize[i];
        } else {
            cout << "Process " << i+1 << " -> Not allocated\n";
        }
    }

    // ----------- WORST FIT -----------
    int blockWF[numBlocks];
    for(int i=0;i<numBlocks;i++) blockWF[i]=blockSize[i];

    cout << "\nWorst-Fit Allocation:\n";
    for(int i=0;i<numProcesses;i++) {
        int worstIndex = -1;
        for(int j=0;j<numBlocks;j++) {
            if(blockWF[j]>=processSize[i]) {
                if(worstIndex==-1 || blockWF[j]>blockWF[worstIndex])
                    worstIndex = j;
            }
        }
        if(worstIndex!=-1) {
            cout << "Process " << i+1 << " -> Block " << worstIndex+1 << "\n";
            blockWF[worstIndex]-=processSize[i];
        } else {
            cout << "Process " << i+1 << " -> Not allocated\n";
        }
    }

    return 0;
}
