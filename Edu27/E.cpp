#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct point_t {
  long long x, y;
};

struct line_t {
  long long x, y1, y2;
};

int n, m, k;
vector<point_t> points;

int get_min_coordinate(vector<point_t> pts, int n, int m, long long mid) {
  vector<line_t> verticle;
  vector<int> y_lines;
  verticle.reserve(pts.size() * 2);
  y_lines.reserve(pts.size() * 2 + 2);

  for (const point_t &point : pts) {
    verticle.push_back(
      line_t({point.x - mid, point.y - mid, point.y + mid})
    );
    y_lines.push_back(point.y - mid);
    y_lines.push_back(point.y + mid);
    y_lines.push_back(point.y + mid + 1);
  }

  sort(
    verticle.begin(), 
    verticle.end(),
    [] (const line_t &lhs, const line_t &rhs) {
      return lhs.x < rhs.x;
    }
  );

  y_lines.push_back(1);
  y_lines.push_back(m);
  sort(y_lines.begin(), y_lines.end());

  for (int y : y_lines) {
    if (y < 1 || y > m)
      continue;

    int cover_end = 0, counter = 0;
    for (const line_t &line : verticle) 
      if (line.y1 <= y && line.y2 >= y) {
        if (cover_end + 1 < line.x)
          return y;
        cover_end = line.x + 2 * mid;
      }
    if (cover_end < n)
      return y;
  }
  return 0;
}

point_t check_coverage(long long mid) {
  vector<point_t> pts = points;
  int min_y = get_min_coordinate(pts, n, m, mid);
  for (point_t &point : pts)
    swap(point.x, point.y);
  int min_x = get_min_coordinate(pts, m, n, mid);
  return point_t({min_x, min_y});
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  points.assign(k, point_t());
  for (int i = 0; i < k; i++)
    scanf("%lld %lld", &points[i].x, &points[i].y);

  long long lower = 0, upper = max(n, m);
  while (lower <= upper) {
    long long mid = (lower + upper) >> 1;
    point_t uncovered = check_coverage(mid);
    if (uncovered.x == 0) {
      upper = mid - 1;
    }
    else {
      points.push_back({uncovered.x + mid, uncovered.y + mid});
      point_t uncovered = check_coverage(mid);
      points.pop_back();

      if (uncovered.x == 0) 
        upper = mid - 1;
      else
        lower = mid + 1;
    }
  }

  printf("%lld\n", upper + 1);
  return 0;
}
