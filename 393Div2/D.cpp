#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long t[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> t[i + 1];
    }

    long long dp[n + 1];
    for (int i = 1; i <= n; i++)
        dp[i] = LLONG_MAX / 4;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 20;
        for (int j = max(1, i - 1500); j < i; j++) {
            if (t[i] - t[j] < 90)
                dp[i] = min(dp[i], dp[j - 1] + 50);
            if (t[i] - t[j] < 1440)
                dp[i] = min(dp[i], dp[j - 1] + 120);
        }
    }


    long long charged = 0;
    for (int i = 0; i < n; i++) {
        long long fee = dp[i + 1] - charged;
        cout << fee << "\n";
        charged += fee;
    }

    return 0;
}
