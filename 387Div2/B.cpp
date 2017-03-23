#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string gene;
    cin >> gene;

    if (n % 4 != 0) {
        cout << "===\n";
        return 0;
    }
     
    int uk = 0;
    int A = 0, G = 0, C = 0, T = 0;
    for (char ch: gene) {
        if (ch == '?')
            uk++;
        else if (ch == 'A')
            A++;
        else if (ch == 'G')
            G++;
        else if (ch == 'C')
            C++;
        else 
            T++;
    }
    
    n /= 4; 

    if (A > n || G > n || C > n || T > n) {
        cout << "===\n";
        return 0;
    }

    for (int i = 0; i < gene.size(); i++) {
        if (gene[i] == '?') {
            if (A < n) {
                gene[i] = 'A';
                A++;
            }
            else if (G < n) {
                gene[i] = 'G';
                G++;
            }
            else if (C < n) {
                gene[i] = 'C';
                C++;
            }
            else if (T < n) {
                gene[i] = 'T';
                T++;
            }
        }
    }
    cout << gene << "\n";
}
