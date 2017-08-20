#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> d;
vector<vector<pair<int, int>>> adj_list;

vector<bool> visited;
vector<int> level_order;
vector<pair<int, int>> parent;

vector<int> subset;

void build_tree() {
  visited.assign(n, false);
  parent.assign(n, {-1, 0});
  level_order.reserve(n);
  
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    level_order.push_back(u);

    for (auto edge : adj_list[u]) {
      int v = edge.first;
      int idx = edge.second;
      if (!visited[v]) {
        visited[v] = true;
        parent[v] = {u, idx};
        q.push(v);
      }
    }
  }
}

void construct() {
  subset.reserve(n);
  for (int i = n - 1; i >= 0; i--) {
    int u = level_order[i];
    if (d[u] == 1) {
      subset.push_back(parent[u].second);
      d[parent[u].first] = 1 - d[parent[u].first];
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  d.assign(n, 0);
  adj_list.assign(n, vector<pair<int, int>>());

  int deg_sum = 0;
  bool wildcard = false;

  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    if (d[i] == -1)
      wildcard = true;
    else
      deg_sum += d[i];
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    adj_list[u].push_back({v, i + 1});
    adj_list[v].push_back({u, i + 1});
  }

  if (deg_sum % 2 == 1 && !wildcard) {
    printf("-1\n");
    return 0;
  }
  
  bool need_one = deg_sum % 2 == 1;
  for (int i = 0; i < n; i++) {
    if (d[i] == -1 && need_one) {
      d[i] = 1;
      need_one = false;
    }
    else if (d[i] == -1) {
      d[i] = 0;
    }
  }

  build_tree();
  construct();

  printf("%lu\n", subset.size());

  for (int idx : subset) 
    printf("%d\n", idx);

  return 0;
}
