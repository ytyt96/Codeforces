#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> shows(n);
  for (int i = 0; i < n; i++) 
    scanf("%d %d", &shows[i].first, &shows[i].second);
  sort(shows.begin(), shows.end());

  int TV1 = 0, TV2 = 0;
  bool possible = true;
  for (pair<int, int> show : shows) {
    if (show.first >= TV1) 
      TV1 = show.second + 1;
    else if (show.first >= TV2)
      TV2 = show.second + 1;
    else {
      possible = false;
      break;
    }
  }

  printf(possible ? "YES\n" : "NO\n");
  return 0;
}
