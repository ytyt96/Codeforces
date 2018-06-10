#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 4098

bool possible = false;
string number;

int calc(char x, char y) {
  string local = number;
  int answer = 0;

  size_t pos = local.rfind(y);
  if (pos == string::npos)
    return INF;
  answer += local.size() - 1 - pos;
  local.erase(pos, 1);

  pos = local.rfind(x);
  if (pos == string::npos)
    return INF;
  answer += local.size() - 1 - pos;
  local.erase(pos, 1);

  if (!local.empty() && local[0] == '0') {
    pos = local.find_first_not_of('0');
    if (pos == string::npos)
      return INF;
    answer += pos;
  }
  possible = true;
  return answer;
}

int main() {
  cin >> number;
  int answer = min(min(calc('0', '0'), calc('2', '5')),
                   min(calc('5', '0'), calc('7', '5')));

  if (!possible)
    answer = -1;
  cout << answer << "\n";
  return 0;
}
