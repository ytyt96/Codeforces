#include <bits/stdc++.h>

using namespace std;

bool is_valid(int *digits, const string &b, int pos, int idx) {
    if (pos == b.size()) {
        return true;
    }

    string c;

    for (int i = 0; i < 10; i++) {
        c += string(idx == i ? digits[i] - 1 : digits[i], '0' + i);
    }

    return stoll(c) <= stoll(b.substr(pos));
}

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() < b.size()) {
        sort(a.rbegin(), a.rend());
        cout << a << "\n";
        return 0;
    }

    int digits[10] = {0};
    for (char ch : a) {
        digits[ch - '0']++;
    }

    for (int i = 0; i < a.size(); i++) {
        int idx = b[i] - '0';

        if (digits[idx] != 0 && !is_valid(digits, b, i + 1, idx)) {
            idx--;
        }

        while (digits[idx] == 0) {
            idx--;
        }

        cout << idx;

        digits[idx]--;
        if (idx < b[i] - '0') {
            string c;
            for (int j = 0; j < 10; j++) {
                c += string(digits[j], '0' + j); 
            }
            sort(c.rbegin(), c.rend());
            cout << c << "\n";
            return 0;
        }
    }
}
