#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, m , k;
    cin >> n >> m >> k;
    m -= n;
    long long lower = 0, upper = m;

    long long sol = 0;
    while (lower <= upper) {
        long long mid = (lower + upper) / 2;
        long long num = 0, cn = min(k - 1, mid);
        num += ((mid- 1) + (mid - cn)) * cn / 2;
        cn = min(n - k, mid);
        num += (mid - 1 + (mid - cn)) * cn / 2;
        num += mid;

        if (num <= m) {
            sol = mid;
            lower = mid + 1;
        }
        else
            upper = mid - 1;
    }
    cout << sol + 1 << "\n";
    return 0;
}
