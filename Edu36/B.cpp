#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pos, l, r;
    scanf("%d %d %d %d", &n, &pos, &l, &r);

    int ans = 0;
    if (pos < l) {
        ans = r == n ? l - pos + 1 : r - pos + 2;
    }
    else if (pos > r) {
        ans = l == 1 ? pos - r + 1 : pos - l + 2;
    }
    else {
        if (l == 1 && r == n) {
            ans = 0;
        }
        else if (l == 1) {
            ans = r  - pos + 1;
        }
        else if (r == n) {
            ans = pos - l + 1;
        }
        else {
            ans =  min(pos - l, r - pos) * 2 + max(pos - l, r - pos) + 2;
        }
    }
    printf("%d\n", ans);
}
