#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, k, cnt = 0;
  vector<int> index(101, -1);

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n && cnt < k; i++) {
    int x;
    scanf("%d", &x);
    if (index[x] == -1) {
      index[x] = i + 1;
      cnt++;
    }
  }

  if (cnt == k) {
    printf("YES\n");
    for (int i = 1; i <= 100; i++)
      if (index[i] != -1)
        printf("%d ", index[i]);
    printf("\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
