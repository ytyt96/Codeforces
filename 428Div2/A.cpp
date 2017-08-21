#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int idx = -1, candy = 0;
  for (int i = 0; i < n; i++) {
    int new_candy;
    scanf("%d", &new_candy);
    candy += new_candy;
    int gift = min(8, candy);
    k -= gift;
    candy -= gift;
    if (k <= 0) {
      idx = i + 1;
      break;
    }
  }

  printf("%d\n", idx);
  return 0;
}
