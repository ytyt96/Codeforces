#include <iostream>
#include <vector>

using namespace std;

int diff(int num1, int num2) {
  int retval = 0;
  for (int i = 0; i < 6; i++) {
    int digit1 = num1 % 10, digit2 = num2 % 10;
    num1 /= 10, num2 /= 10;
    if (digit1 != digit2)
      retval++;
  }
  return retval;
}

bool lucky(int num) {
  int first = 0, last = 0;
  for (int i = 0; i < 3; i++) {
    first += num % 10;
    num /= 10;
  }
  for (int i = 0; i < 3; i++) {
    last += num % 10;
    num /= 10;
  }
  return first == last;
}

int main() {
  int ticket;
  scanf("%d", &ticket);

  int answer = 233;
  for (int i = 0; i <= 999999; i++) {
    if (lucky(i))
      answer = min(answer, diff(i, ticket));
  }
  printf("%d\n", answer);
}
