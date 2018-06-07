#include <vector>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

ull n, m, A, B, C;
vector<vector<ull>> adj_list;
vector<vector<ull>> prefix_sum;

vector<ull> idx;
vector<bitset<200005>> connected;

void preprocess() {
  prefix_sum.assign(n, vector<ull>());
  idx.assign(n, -1);
  connected.reserve(1000);
  ull heavy_threshold = max(400., sqrt(m));

  for (ull i = 0; i < n; i++) {
    sort(adj_list[i].begin(), adj_list[i].end());

    prefix_sum[i].assign(adj_list[i].size() + 1, 0);
    for (ull j = 0; j < adj_list[i].size(); j++)
      prefix_sum[i][j + 1] = prefix_sum[i][j] + adj_list[i][j];

    if (adj_list[i].size() >= heavy_threshold) {
      idx[i] = connected.size();
      connected.push_back(bitset<200005>());
      for (ull u: adj_list[i])
        connected[idx[i]][u] = 1;
    }
  }
}

ull all_triple() {
  ull retval = 0;
  for (ull i = 0; i < n; i++) {
    ull less = i, greater = n - i - 1;
    retval += A * i * (greater * (greater - 1) / 2);
    retval += B * i * less * greater;
    retval += C * i * (less * (less - 1) / 2);
  }
  return retval;
}

ull invalid_type1() {
  ull retval = 0;
  for (ull v = 0; v < n; v++) {
    for (ull u: adj_list[v]) {
      if (u > v)
        break;

      ull cnt = u, sum = (u - 1) * cnt / 2;
      retval += A * sum + B * cnt * u + C * cnt * v;

      cnt = v - 1 - u;
      sum = (u + v) * cnt / 2;
      retval += A * cnt * u + B * sum + C * cnt * v;
    }
  
    ull prev_sum = 0;
    for (ull i = 0; i < adj_list[v].size(); i++) {
      ull u = adj_list[v][i];
      if (u > v)
        break;
      ull cnt = i;
      retval -= A * prev_sum + B * cnt * u + C * cnt * v;
      prev_sum += u;
    }
  }
  return retval;
}

ull invalid_subtype1() {
  ull retval = 0, sum = 0, cnt = 0;

  for (ull u = 0; u < n; u++) {
    retval += sum + C * cnt * u;
    for (ull v: adj_list[u]) {
      if (v > u)
        break;
      cnt++;
      sum += A * v + B * u;
    }
  }
  return retval;
}

ull invalid_subtype2() {
  ull retval = 0;

  for (ull u = 0; u < n; u++) {
    for (ull v: adj_list[u]) {
      if (v > u)
        break;
      auto &v_list = adj_list[v];

      auto it = lower_bound(v_list.begin(), v_list.end(), v);
      ull pos1 = it - v_list.begin();
      ull sum = prefix_sum[v][pos1] - prefix_sum[v][0];
      retval += A * sum + B * pos1 * v + C * pos1 * u;

      it = lower_bound(v_list.begin(), v_list.end(), u);
      ull pos2 = it - v_list.begin();
      sum = prefix_sum[v][pos2] - prefix_sum[v][pos1];
      retval += A * (pos2 - pos1) * v + B * sum + C * (pos2 - pos1) * u;
    }
  }
  return retval;
}

ull invalid_subtype3_heavy(ull u) {
  ull retval = 0;
  for (ull v = 0; v < u; v++) {
    if (connected[idx[u]][v] == 0)
      continue;
    for (ull w: adj_list[v]) {
      if (w > v)
        break;
      if (connected[idx[u]][w])
        retval += A * w + B * v + C * u;
    }
  }
  return retval;
}

ull invalid_subtype3_light(ull u) {
  ull retval = 0;
  for (ull i = 0; i < adj_list[u].size(); i++) {
    ull v = adj_list[u][i];
    if (v > u)
      break;
    if (idx[v] != -1) {
      for (ull j = 0; j < i; j++) {
        ull w = adj_list[u][j];
        if (connected[idx[v]][w])
          retval += A * w + B * v + C * u;
      }
    } else {
      bitset<200005> v_connected;
      for (ull w: adj_list[v]) {
        if (w > v)
          break;
        v_connected[w] = 1;
      }

      for (ull j = 0; j < i; j++) {
        ull w = adj_list[u][j];
        if (v_connected[w])
          retval += A * w + B * v + C * u;
      }
    }
  }
  return retval;
}

ull invalid_subtype3() {
  ull retval = 0;
  for (ull u = 0; u < n; u++) {
    if (idx[u] != -1) {
      retval += invalid_subtype3_heavy(u);
    } else {
      retval += invalid_subtype3_light(u);
    }
  }
  return retval;
}

ull invalid_type2() {
  ull retval = 0;
  retval += invalid_subtype1();
  retval -= invalid_subtype2();
  retval += invalid_subtype3();
  return retval;
}

ull invalid_triple() {
  return invalid_type1() + invalid_type2();
}

int main() {
  scanf("%llu %llu", &n, &m);
  scanf("%llu %llu %llu", &A, &B, &C);
  adj_list.assign(n, vector<ull>());

  for (ull i = 0; i < m; i++) {
    ull u, v;
    scanf("%llu %llu", &u, &v);
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  preprocess();
  printf("%llu\n", all_triple() - invalid_triple());
}
