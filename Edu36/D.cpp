#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj_list;
vector<int> stk, cycle;
vector<bool> visited, in_stk;
pair<int, int> removed;

bool dfs(int u, bool initial) {
    visited[u] = true;
    in_stk[u] = true;

    if (initial) {
        stk.push_back(u);
    }

    for (int v : adj_list[u]) {
        if (!initial && make_pair(u, v) == removed) {
            continue;
        }
        if (!visited[v]) {
            if (dfs(v, initial) == false) {
                return false;
            }
        }
        else if (in_stk[v]) {
            if (initial) {
                cycle.push_back(v);

                while (stk.back() != v) {
                    cycle.push_back(stk.back());
                    stk.pop_back();
                }
                cycle.push_back(v);
            }
            return false;
        }
    }
    
    if (initial) {
        stk.pop_back();
    }
    in_stk[u] = false;

    return true;
}

bool acyclic(bool initial) {
    visited.assign(n, false);

    bool is_acyclic = true;
    for (int i = 0; i < n && is_acyclic; i++) {
        in_stk.assign(n, false);
        if (!visited[i]) {
            is_acyclic &= dfs(i, initial);
        }
    }

    return is_acyclic;
}

int main() {
    scanf("%d %d", &n, &m);

    adj_list.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj_list[u - 1].push_back(v - 1);
    }

    if (acyclic(true)) {
        printf("YES\n");
        return 0;
    }

    for (int i = 0; i < cycle.size() - 1; i++) {
        removed = {cycle[i + 1], cycle[i]};
        if (acyclic( false)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}
