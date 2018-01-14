#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (k % a == 0) {
            ans = min(ans, k / a);
        }
    }
    printf("%d\n", ans);
    return 0;
}
