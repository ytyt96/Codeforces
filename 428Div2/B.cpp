#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int four_seats = n, two_seats = n * 2, one_seats = 0;

  int remain_one = 0, remain_two = 0;
  bool possible = true;

  for (int i = 0; i < k; i++) {
    int group;
    scanf("%d", &group);
    
    while (group >= 3) {
      if (four_seats) {
        four_seats -= 1;
        group = max(0, group - 4); 
      }
      else if (two_seats) {
        two_seats -= 1;
        group = max(0, group - 2);
      }
      else {
        possible = false;
        break;
      }
    }

    if (group == 1)
      remain_one += 1;
    else if (group == 2)
      remain_two += 1;
  }

  while (remain_two) {
    if (four_seats) {
      four_seats -= 1;
      one_seats += 1;
      remain_two--;
    }
    else if (two_seats) {
      two_seats -= 1;
      remain_two--;
    }
    else {
      remain_two--;
      remain_one += 2;
    }
  }

  if (four_seats * 2 + two_seats + one_seats < remain_one)
    possible = false;

  printf(possible ? "YES\n" : "NO\n");
  return 0;
}
