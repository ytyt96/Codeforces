#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int lat = 0;
    bool good = true;
    for (int i = 0; i < n; i++) {
        int dist;
        string dir;
        cin >> dist >> dir;
        if (lat == 0 && dir != "South")
            good = false;
        if (lat == 20000 && dir != "North")
            good = false;
        if (dir == "North")
            lat -= dist;
        if (dir == "South")
            lat += dist;
        if (lat < 0 || lat > 20000)
            good = false;
    }
    if (lat != 0)
        good = false;
    if (good)
        cout << "YES\n";
    else
        cout << "NO\n";
	return 0;
}
