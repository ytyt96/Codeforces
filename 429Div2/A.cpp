#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int hash[26];
  memset(hash, 0, sizeof(hash));
  bool happy = true;
  while (n--) {
    char color;
    scanf(" %c", &color);
    if (++hash[color - 'a'] > k)
      happy = false;
  }
  printf(happy ? "YES\n" : "NO\n"); 
  return 0;
}
