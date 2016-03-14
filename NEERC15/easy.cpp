#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    int n, k;
    ifstream fin("easy.in");
    ofstream fout("easy.out");
    fin >> n >> k;
    vector<int> index(n, 0);
    vector<vector<int>> easy(n);
    for (int i = 0; i < n; i++){
        int m;
        fin >> m;
        vector<int> problem(m);
        for (int j = 0; j < m; j++)
            fin >> problem[j];
        easy[i] = problem;
    }

    int total = 0, judge = 0;

    while (k){
        if (index[judge] >= easy[judge].size()){
            total += 50;
            k--;
        }
        else{
            if (easy[judge][index[judge]] >= total){
                total += easy[judge][index[judge]];
                k--;
            }
            index[judge]++;
        }
        judge = (judge + 1) % n;
    }
    fout << total << "\n";
}
