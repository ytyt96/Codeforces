#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int remain = 240;
    int sol = 0;
    remain -= k;
    for (int i = 1; i <= n; i++)
        if (i * 5 <= remain) {
            remain -= i * 5;
            sol++;
        }
    cout << sol << "\n";
	return 0;
}
