#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, d;
vector<int> pencils, sum;

int main() {
  scanf("%d %d %d", &n, &k, &d);
  pencils.assign(n, 0);
  for (int i = 0; i < n; i++)
    scanf("%d", &pencils[i]);

  sort(pencils.begin(), pencils.end());
  sum.assign(n + 1, 0);

  int j = 0;
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i];
    while (j < i && pencils[i] - pencils[j] > d)
      j++;
    if (i - j + 1 < k)
      continue;
    if (j == 0 || sum[i + 1 - k] - sum[j - 1] > 0)
      sum[i + 1]++;
  }

  if (sum[n] - sum[n - 1] > 0)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
