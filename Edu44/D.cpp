#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, H;

long long calc_spot(long long high) {
  long long min_pack = 0, spot = 0;

  if (high > H) {
    spot += high - H;
    min_pack += (H + high - 1) * (high - H) / 2;
  }
  min_pack += (high + 1) * high / 2;
  spot += high;

  if (min_pack > n)
    return -1;
    
  long long rem = n - min_pack;
  spot += rem / high;
  rem %= high;

  if (rem > 0)
    spot += 1;
  return spot;
}

long long binary_search_answer(long long lower, long long upper) {
  long long answer = n;
  while (lower <= upper) {
    long long mid = (lower + upper) >> 1;
    long long spot = calc_spot(mid);

    if (spot == -1) {
      upper = mid - 1;
    } else {
      answer = min(answer, spot);
      lower = mid + 1;
    }
  }
  return answer;
}

int main() {
  scanf("%lld %lld", &n, &H);
  long long answer = min(n, binary_search_answer(1, sqrt(2 * n)));
  printf("%lld\n", answer);
  return 0;
}
