#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> idle(n, 0);
    for (int i = 0; i < q; i++) {
        int t, k, d;
        cin >> t >> k >> d;
        int sum = 0, s = 0;
        
        for (int j = 0; j < n; j++) {
            if (idle[j] <= t) {
                s++;
                if (s == k)
                    break;
            }
        }
        if (s == k) {
            s = 0;
            for (int j = 0; j < n; j++) {
                if (idle[j] <= t) {
                    s++;
                    sum += j + 1;
                    idle[j] = t + d;
                    if (s == k)
                        break;
                }
            }
            cout << sum << "\n";
        }
        else 
            cout << "-1\n";
    }
    return 0;
}
