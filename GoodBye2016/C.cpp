#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &c[i], &d[i]);

    int lower = -30000000, upper = 45000000;
    int sol = -1;
    while (lower <= upper) {
        int mid = (lower + upper) >> 1;
        
        int result = 0;
        int rank = mid;

        for (int i = n - 1; i >= 0; i--) {
            rank -= c[i];
            if (rank < 1900 && d[i] == 1) {
                result = -1;
                break;
            }
            if (rank >= 1900 && d[i] == 2) {
                result = 1;
                break;
            }
        }

        if (result == 0)
            sol = mid;
        if (result == -1 || result == 0)
            lower = mid + 1;
        else 
            upper = mid - 1;
    }
    
    if (sol == 45000000)
        printf("Infinity\n");
    else if (sol == -1)
        printf("Impossible\n");
    else
        printf("%d\n", sol);
}
