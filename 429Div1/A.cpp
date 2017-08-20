#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int m;
  scanf("%d", &m);
  vector<int> A(m);
  vector<pair<int, int>> B(m);
  for (int i = 0; i < m; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d", &B[i].first);
    B[i].second = i;
  }

  sort(B.begin(), B.end());
  sort(A.rbegin(), A.rend());

  int output[m];
  for (int i = 0; i < m; i++) 
    output[B[i].second] = A[i];

  for (int i = 0; i < m; i++)
    printf("%d ", output[i]);
  
  return 0;
}
