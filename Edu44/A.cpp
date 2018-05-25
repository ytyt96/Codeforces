#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    n >>= 1;

    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    sort(p, p + n);

    int black = 0, white = 0;
    for (int i = 0; i < n; i++) {
        black += abs(i * 2 - p[i]);
        white += abs(i * 2 + 1 - p[i]);
    }

    printf("%d\n", min(black, white));
    return 0;
}
