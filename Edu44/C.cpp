#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  long long l;
  scanf("%d %d %lld", &n, &k, &l);

  vector<long long> staves(n * k);
  for (int i = 0; i < n * k; i++)
    scanf("%lld", &staves[i]);
  sort(staves.begin(), staves.end());

  auto it = upper_bound(staves.begin(), staves.end(), staves[0] + l);
  int upper = it - staves.begin();

  if (upper < n) {
    printf("0\n");
  } else {
    int curr = 0, barrel = 0;
    long long volume = 0;
    while (barrel < n) {
      volume += staves[curr];
      barrel++;
      curr += min(upper - curr - (n - barrel), k);
    }

    printf("%lld\n", volume);
  }

  return 0;
}
