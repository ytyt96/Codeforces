#include <bits/stdc++.h>

using namespace std;

int main(){
    string word;
    cin >> word;
    map<char, int> counter;
    for (char ch : word)
        counter[ch]++;
    int answer = INT_MAX;
    answer = min(counter['B'], answer);
    answer = min(counter['u'] / 2, answer);
    answer = min(counter['l'], answer);
    answer = min(counter['b'], answer);
    answer = min(counter['a'] / 2, answer);
    answer = min(counter['s'], answer);
    answer = min(counter['r'], answer);
    cout << answer << "\n";
	return 0;
}
