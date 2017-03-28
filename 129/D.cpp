#include <iostream>
#include <cstring>

using namespace std;

int digits[20];
long long dp[20][20];

long long dfs(int pos, int first, bool limited) {
    if (pos < 0)
        return 1;

    if (dp[pos][first] != -1 && !limited)
        return dp[pos][first];

    int end = limited ? digits[pos] : 9;

    long long answer = 0;
    for (int i = 0; i <= end; i++) {
        if (pos == 0 && first != 0 && first != i)
            continue;

        if (first == 0)
            answer += dfs(pos - 1, i, limited && i == end);
        else
            answer += dfs(pos - 1, first, limited && i == end);
    }
    if (!limited)
        dp[pos][first] = answer;
    return answer;
}

long long solve(long long n) {
    int pos = 0;
    while (n) {
        digits[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1, 0, true);
}

int main() {
    memset(dp, -1, sizeof dp);
    long long l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << "\n";
    return 0;
}
