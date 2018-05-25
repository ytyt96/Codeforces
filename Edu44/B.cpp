#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<bool>> switches(n, vector<bool>(m, false));
    vector<int> conn(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            scanf(" %c", &ch);
            switches[i][j] = ch == '1';

            if (switches[i][j])
                conn[j] += 1;
        }
    }

    bool possible = false; 
    for (int i = 0; i < n; i++) {
        bool can_ignore = true;
        for (int j = 0; j < m; j++) {
            if (switches[i][j] && conn[j] == 1) {
                can_ignore = false;
                break;
            }
        }

        if (can_ignore) {
            possible = true;
            break;
        }
    }

    printf("%s\n", possible ? "YES" : "NO");
    return 0;
}
