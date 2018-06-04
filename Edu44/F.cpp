#include <cstdio>
#include <cstring>

#define MOD 1000000007
#define MAGIC 1009
#define MAXN 200005

using namespace std;

int n, m;
char s[MAXN];
unsigned long long prefix[26][MAXN];
int suffix[MAXN][26];
unsigned long long powers[MAXN];

unsigned long long hash(int ch, int x, int len) {
  int y = x + len - 1;
  unsigned long long result = MOD + prefix[ch][y];
  result -= prefix[ch][x - 1] * powers[len] % MOD;
  return result % MOD;
}

void preprocess() {
  powers[0] = 1;
  for (int i = 1; i <= n; i++)
    powers[i] = powers[i - 1] * MAGIC % MOD;

  for (int i = 0; i < 26; i++) {
    prefix[i][0] = 0;
    for (int j = 0; j < n; j++) {
      char ch = s[j] == 'a' + i ? '1' : '0';
      prefix[i][j + 1] = prefix[i][j] * MAGIC % MOD + ch;
      prefix[i][j + 1] %= MOD;
    }
  }

  for (int i = 0; i < 26; i++)
    suffix[n][i] = i;

  for (int i = n - 1; i >= 0; i--) {
    suffix[i][0] = s[i] - 'a';
    int k = 1;
    for (int j = 0; j < 26; j++) {
      if (suffix[i + 1][j] == s[i] - 'a')
        continue;
      suffix[i][k] = suffix[i + 1][j];
      k++;
    }
  }
}

int main() {
  scanf("%d %d %s", &n, &m, s);
  preprocess();

  for (int i = 0; i < m; i++) {
    int x, y, len;
    scanf("%d %d %d", &x, &y, &len);

    bool possible = true;
    for (int j = 0; j < 26 && possible; j++)
      if (hash(suffix[x - 1][j], x, len) != hash(suffix[y - 1][j], y, len))
        possible = false;

    printf(possible ? "YES\n" : "NO\n");
  }
  return 0;
}
