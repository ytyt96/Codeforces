#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> sub(n, false);

    int c = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < 0) {
           sub[i] = true; 
           c++;
        }
    }

    if (c > k) {
        cout << "-1\n";
        return 0;
    }

    bool f = c;

    k -= c;

    vector<int> r(n + 1, 0);

    c = 0;
    int p = -1;
    bool s = true;

    int last = -1;

    for (int i = 0; i < n; i++) {
        if (sub[i]) {
            if (s) {
                c++;

                s = false;
                if (p != -1) {
                    r[i - p]++;
                }
            }
        }
        else {
            if (!s)  {
                p = i;
                s = true;
                c++;
            }
        }
    }
    
    if (f && !sub[n - 1])
        last = n - p;

    for (int i = 1; i < n + 1; i++) {
        while (k - i >= 0 && r[i]) {
            c -= 2;
            k -= i;
            r[i] -= 1;
        }
        if (k - i < 0) {
            if (last != -1 && k - last >= 0) {
                c--;
                last = -1;
            }
            break;
        }
    }

    if (last != -1 && k - last >= 0)
        c--;
    cout << c << '\n';
}
