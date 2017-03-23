#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string voter;
    cin >> voter;
    
    int D = 0;
    int R = 0;

    int DD = 0;
    int RR = 0;
    for (int i = 0; i < voter.size(); i++)
        if (voter[i] == 'D')
            DD++;
        else
            RR++;

    while (RR > 0 && DD > 0) {
        for (int i = 0; i < voter.size(); i++) {
            if (voter[i] == 'D') {
                if (D >= 0) {
                    R--;
                    RR--;
                }
                else {
                    voter[i] = ' ';
                    D++;
                }
            }

            if (voter[i] == 'R') {
                if (R >= 0) {
                    D--;
                    DD--;
                }
                else {
                    voter[i] = ' ';
                    R++;
                }
            }
        }
    }

    if (RR > 0)
        cout << "R\n";
    else
        cout << "D\n";
}
