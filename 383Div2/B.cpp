#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int P = 0, E = 0, C = 0;

    set<string> PS;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        P++;
        PS.insert(word);
    }

    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;
        if (PS.count(word)) {
            P--;
            C++;
        }
        else
            E++;
    }

    if (C % 2 == 1)
        P += C / 2 + 1;
    else
        P += C / 2;
    E += C / 2;

    if (P > E)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
