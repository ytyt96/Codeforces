#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    unordered_map<int, int> hash;

    unordered_map<int, vector<int>> raw;

    for (int i = 0; i < n; i++) {
        int idx, bid;
        scanf("%d %d", &idx, &bid);
        hash[idx] = bid;
        raw[idx].push_back(bid);
    }

    vector<pair<int, int>> bids(hash.size());

    int idx = 0;
    for (auto it: hash)
        bids[idx++] = {it.second, it.first};

    sort(bids.begin(), bids.end());

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        unordered_set<int> kh;
        for (int j = 0; j < k; j++) {
            int l;
            scanf("%d", &l);
            kh.insert(l);
        }

        int first = -1, second = -1;

        for (int i = bids.size() - 1; i >= 0; i--) {
            if (kh.count(bids[i].second) == 0) {
                if (first == -1)
                    first = bids[i].second;
                else if (second == -1)
                    second = bids[i].second;
                else
                    break;
            }
        }

        if (first == -1 && second == -1)
            printf("0 0\n");
        else if (second == -1)
            printf("%d %d\n", first, raw[first][0]);
        else {
            auto it = lower_bound(raw[first].begin(), raw[first].end(), 
                                  hash[second]);
            printf("%d %d\n", first, *it);
        }
    }

    return 0;
}
