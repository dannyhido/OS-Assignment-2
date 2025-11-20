// Danny Hido
// Operating Systems Assignment 2
// 11/20/2025
// Bankers Algoritm

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "input.txt not found.";
        return 1;
    }

    int P; // processes
    int R; // resources
    fin >> P >> R;

    vector<int> total(R);
    for (int i = 0; i < R; i++){ 
        fin >> total[i];
    }

    vector<vector<int>> alloc(P, vector<int>(R));
    vector<vector<int>> max(P, vector<int>(R));
    vector<vector<int>> need(P, vector<int>(R));
    vector<int> available(R);

    // Allocation in
    for (int i = 0; i < P; i++){
        for (int j = 0; j < R; j++){
            fin >> alloc[i][j];
        }
    }

    // Max in
    for (int i = 0; i < P; i++){
        for (int j = 0; j < R; j++){
            fin >> max[i][j];
        }
    }

    // aeed = max - allocation
    for (int i = 0; i < P; i++){
        for (int j = 0; j < R; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // available = total - sum(allocation)
    for (int j = 0; j < R; j++) {
        int sum = 0;
        for (int i = 0; i < P; i++) sum += alloc[i][j];
        available[j] = total[j] - sum;
    }



    // Bankers Algoritm
    vector<int> safeSeq(P);
    vector<bool> finished(P, false);
    int count = 0;

    while (count < P) {
        bool found = false;

        for (int p = 0; p < P; p++) {
            if (!finished[p]) {
                bool canRun = true;

                for (int j = 0; j < R; j++)
                    if (need[p][j] > available[j]) {
                        canRun = false;
                        break;
                    }

                if (canRun) {
                    for (int j = 0; j < R; j++)
                        available[j] += alloc[p][j];

                    safeSeq[count++] = p;
                    finished[p] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is NOT in a safe state.";
            return 0;
        }
    }

    // print sequence
    cout << "System IS in a safe state." << endl << "Safe sequence: ";
    for (int i = 0; i < P; i++)
        cout << "P" << safeSeq[i] << (i == P-1 ? "" : " -> ");
    cout << endl;

    return 0;
}
