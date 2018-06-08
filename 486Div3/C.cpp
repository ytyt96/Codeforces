#include <cstdio>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

int main() {
  unordered_map<int, pair<int, int>> hash; 

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k, sum = 0;
    scanf("%d", &k);
    vector<int> elem(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &elem[j]);
      sum += elem[j];
    }

    for (int j = 0; j < k; j++) {
      int key = sum - elem[j];
      if (hash.find(key) != hash.end()) {
        auto &value = hash[key];
        if (value.first == i + 1)
          continue;
        printf("YES\n%d %d\n%d %d\n", value.first, value.second, i + 1, j + 1);
        return 0;
      } else {
        hash[key] = {i + 1, j + 1};
      }
    }
  }
  printf("NO\n");
  return 0;
}
