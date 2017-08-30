#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  vector<int> ratings(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &ratings[i]);
  sort(ratings.begin(), ratings.end());
  printf(ratings[n / 2] > ratings[n / 2 - 1] ? "YES\n" : "NO\n");
  return 0;
}
