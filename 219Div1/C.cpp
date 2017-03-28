#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

long long n, m, d;
long long a[350], b[350], t[350];
long long dp[2][150050];

int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i] >> t[i];

    t[0] = 0;

    memset(dp, 128, sizeof dp);

    for (int i = 1; i <= n; i++)
        dp[0][i] = 0;

    int pre = 0, cur = 1;

    for (int i = 1; i <= m; i++) {
        deque<long long> dq;
        int left = 1, right = 1;
        dq.push_back(dp[pre][1]);

        for (int j = 1; j <= n; j++) {
            while (left < j - d * (t[i] - t[i - 1])) {
                if (dq.front() == dp[pre][left])
                    dq.pop_front();
                left++;
            }
            while (right < j + d * (t[i] - t[i - 1]) && right < n) {
                right++;
                while (!dq.empty() && dp[pre][right] > dq.back())
                    dq.pop_back();
                dq.push_back(dp[pre][right]);
            }
            dp[cur][j] = dq.front() + b[i] - abs(a[i] - j);
        }
        swap(pre, cur);
    }

    long long answer = LLONG_MIN;
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[pre][i]);
    
    cout << answer << "\n";
    return 0;
}
