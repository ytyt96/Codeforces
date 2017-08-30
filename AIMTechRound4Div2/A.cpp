#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  vector<bool> exist(26);
  int used_letter = 0, free_char = 0;

  for (char ch : s) {
    if (exist[ch - 'a'])
      free_char++;
    else {
      exist[ch - 'a'] = true;
      used_letter++;
    }
  }

  if (used_letter + min(free_char, 26 - used_letter) < k)
    cout << "impossible\n";
  else
    cout << max(0, k - used_letter) << "\n";

  return 0;
}
