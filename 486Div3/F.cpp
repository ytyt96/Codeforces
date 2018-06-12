#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF (1LL << 32)

long long dp[2][2050];
bool rain[2050];
int x[2050], p[2050];

int a, n, m;

int main() {
  scanf("%d %d %d", &a, &n, &m);
  a++;
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    for (int j = l + 1; j < r + 1; j++)
      rain[j] = true;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x[i], &p[i]);
    x[i]++;
  }

  memset(dp, 1, sizeof dp);
  dp[0][0] = 0;

  long long min_prev = 0, min_curr = INF;
  int curr_idx = 1, prev_idx = 0;

  for (int i = 1; i <= a; i++) {
    for (int j = 0; j <= m; j++) {
      if (j == 0) {
        dp[curr_idx][j] = rain[i] ? INF : min_prev;
        min_curr = dp[curr_idx][j];
      }
      else {
        if (x[j - 1] == i) {
          dp[curr_idx][j] = min_prev + p[j - 1];
        } else {
          dp[curr_idx][j] = dp[prev_idx][j] + p[j - 1];
        }
        min_curr = min(min_curr, dp[curr_idx][j]);
      }
    }
    swap(curr_idx, prev_idx);
    min_prev = min_curr;
  }

  if (min_prev >= INF)
    printf("-1\n");
  else
    printf("%lld\n", min_prev);
  return 0;
}
