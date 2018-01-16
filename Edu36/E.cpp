#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, q;
    scanf("%lld %lld", &n, &q);

    set<pair<int, int>> workday;

    workday.insert({n, 1});

    long long ans = n;

    for (int i = 0; i < q; i++) {
        long long l, r, k;
        scanf("%lld %lld %lld", &l, &r, &k);

        auto front = workday.lower_bound({l, 0});
        auto back = workday.lower_bound({r, 0});

        if (k == 1) {
            if (front != workday.end() && front->second < l) {
                workday.insert({l - 1, front->second});
                ans += l - front->second;
            }

            if (back != workday.end() && back->first > r && back->second <= r) {
                workday.insert({back->first, r + 1});
                ans += back->first - r;
            }
        }

        int left = l;
        if (front != workday.end()) {
            left = min(left, front->second);
        }

        int right = r;
        if (back != workday.end() && back->second <= r) {
            right = max(back->first, right);
            back++;
        }

        while (front != back) {
            ans -= front->first - front->second + 1;
            front = workday.erase(front);
        }

        if (k == 2) {
            workday.insert({right, left});
            ans += right - left + 1;
        }

        printf("%lld\n", ans);
    }
}
