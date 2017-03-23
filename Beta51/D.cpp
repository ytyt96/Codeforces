#include <bits/stdc++.h>

using namespace std;

#define MOD 2520

int lcm_index[MOD + 1];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


long long dp[20][MOD][48];
int digits[20];

void init() {
    int counter = 0;
    for (int i = 1; i <= MOD; i++)
        if (MOD % i == 0)
            lcm_index[i] = counter++;
    memset(dp, -1, sizeof dp);
}

long long digit_dp(int pos, int pre_sum, int pre_lcm, bool complete) {
    if (pos == -1)
        return (pre_sum % pre_lcm) == 0;
    if (complete && dp[pos][pre_sum][lcm_index[pre_lcm]] != -1)
        return dp[pos][pre_sum][lcm_index[pre_lcm]];

    int upper = complete ? 9 : digits[pos];
    long long local = 0;
    for (int i = 0; i <= upper; i++) {
        int cur_sum = (pre_sum * 10 + i) % MOD;
        int cur_lcm = i == 0 ? pre_lcm : lcm(pre_lcm, i);
        local += digit_dp(pos - 1, cur_sum, cur_lcm, i != upper || complete);
    }
    if (complete)
        dp[pos][pre_sum][lcm_index[pre_lcm]] = local;
    return local;
}

long long solve(long long num) {
    int pos = 0; 
    while (num) {
        digits[pos] = num % 10;
        num /= 10;
        pos++;
    }
    return digit_dp(pos - 1, 0, 1, false);
}

int main() {
    init();

    int t;
    long long l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << "\n";
    }
    
    return 0;
}
