#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> strings(n);
  for (int i = 0; i < n; i++)
    cin >> strings[i];

  sort(strings.begin(), strings.end(),
    [](const string &lhs, const string &rhs) {
      return lhs.size() < rhs.size();
    }
  );

  for (int i = 1; i < n; i++) {
    if (strings[i] != strings[i - 1] && 
      strings[i].find(strings[i - 1]) == string::npos) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for (string str: strings)
    cout << str << "\n";

  return 0;
}
