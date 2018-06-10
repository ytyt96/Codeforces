#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  set<long long> tree;
  for (int i = 0; i < n; i++) {
    long long num;
    scanf("%lld", &num);
    tree.insert(num);
  }

  long long powers[32] = {1};
  for (int i = 1; i < 32; i++)
    powers[i] = (powers[i - 1] << 1);

  vector<long long> answer;

  for (long long x: tree) {
    if (answer.size() == 0)
      answer = {x};

    for (int i = 0; i < 32; i++) {
      auto it1 = tree.find(x + powers[i]);
      if (it1 != tree.end()) {
        answer = {x, *it1};

        auto it2 = tree.find(x + powers[i] * 2);
        if (it2 != tree.end()) {
          answer = {x, *it1, *it2};
          break;
        }
      }
    }

    if (answer.size() == 3)
      break;
  }

  printf("%zu\n", answer.size());
  for (long long x: answer)
    printf("%lld ", x);
  printf("\n");

  return 0;
}
