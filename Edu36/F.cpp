#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> s;

    void add_elems(int n) {
        while (n--) {
            s.push_back(-1);
        }
    }

    int find(int elem) {
        return s[elem] < 0 ? elem : s[elem] = find(s[elem]);
    }

    void set_union(int a, int b) {
        int root1 = find(a), root2 = find(b);
        int new_size = s[root1] + s[root2];
        if (s[root1] < s[root2]) {
            s[root2] = root1;
            s[root1] = new_size;
        }
        else {
            s[root1] = root2;
            s[root2] = new_size;
        }
    }

    int size(int elem) {
        return -s[find(elem)];
    }
};

int n;

vector<pair<int, int>> sorted;
vector<int> idx;
vector<vector<int>> adj_list;

long long calculate_sum() {
    dsu trees;
    trees.add_elems(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int u = sorted[i].second;
        long long partial = 0, path_count = 0;

        for (int v : adj_list[u]) {
            if (idx[v] > i)
                continue;
            
            int size = trees.size(v);
            path_count += size;
            path_count += partial * size;
            partial += size;
            trees.set_union(u, v);
        }

        path_count += 1;
        sum += path_count * sorted[i].first;
    }
    return sum;
}

void update_index() {
    for (int i = 0; i < n; i++) {
        idx[sorted[i].second] = i;
    }
}

int main() {
    scanf("%d", &n);

    sorted.reserve(n);
    adj_list.assign(n, vector<int>());
    idx.assign(n, 0);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sorted.push_back({a, i});
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    sort(sorted.begin(), sorted.end());
    update_index();
    long long max_sum = calculate_sum();

    sort(sorted.rbegin(), sorted.rend());
    update_index();
    long long min_sum = calculate_sum();

    printf("%lld\n", max_sum - min_sum);

    return 0;
}
