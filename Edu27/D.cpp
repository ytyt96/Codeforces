#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> speed_sign;
  int no_pass = 0;
  int sign_miss = 0;
  int speed = 0;

  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    switch (t) {
    case 1:
      scanf("%d", &speed);
      while (!speed_sign.empty() && speed_sign.back() < speed) {
        sign_miss++;
        speed_sign.pop_back();
      }
      break;
    case 2:
      sign_miss += no_pass;
      no_pass = 0;
      break;
    case 3:
      int new_speed;
      scanf("%d", &new_speed);
      speed_sign.push_back(new_speed);
      while (!speed_sign.empty() && speed_sign.back() < speed) {
        sign_miss++;
        speed_sign.pop_back();
      }
      break;
    case 4:
      no_pass = 0;
      break;
    case 5:
      speed_sign.clear();
      break;
    case 6:
      no_pass++;
      break;
    }
  }
  printf("%d\n", sign_miss);
  return 0;
}
