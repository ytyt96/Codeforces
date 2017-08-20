#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  bool odd_num = false;
  while (n--) {
    int num;
    scanf("%d", &num);
    if (num % 2 == 1)
      odd_num = true;
  }
  printf(odd_num ? "First\n" : "Second\n");
  return 0;
}
