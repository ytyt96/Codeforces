#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n, k;
vector<double> memo;
vector<double> p;

double solve(unsigned state, int rem) {
    if (memo[state] >= 0)
        return memo[state];

    double &value = memo[state];
    value = 0;
        
    if (rem == 0)
        return value = 0;

    if (rem == 1) {
        for (int i = 0; i < n; i++)
            if (state & (1 << i))
                return value = p[i];
    }
        
    double prob = 1;
    for (int i = 0; i < n; i++)
        if (state & (1 << i)) 
            prob -= p[i];

    for (int i = 0; i < n; i++)
        if (state & (1 << i)) 
            value += solve(state & ~(1 << i), rem - 1) * (p[i] / (prob + p[i]));
    return value;
}

int main() {
    scanf("%d %d", &n, &k);
    vector<int> index(n, -1);
    int N = n;
    for (int i = 0; i < N; i++) {
        double raw;
        scanf("%lf", &raw);
        if (raw > 1e-7) {
            p.push_back(raw);
            index[i] = p.size() - 1;
        }
        else 
            n--;
    }

    if (k > n)
        k = n;


    vector<double> sol(n);
    memo.assign(1 << n, -1);

    for (unsigned state = 1; state < (1 << n); state++) {
        int counter = 0;
        for (int i = 0; i < n; i++)
            if (state & (1 << i))
                counter++;

        if (counter == k) {
            double prob = solve(state, k);
            for (int i = 0; i < n; i++)
                if (state & (1 << i))
                    sol[i] += prob;
        }
    }
    for (int i = 0; i < N; i++) {
        if (index[i] == -1)
            printf("0.0 ");
        else
            printf("%.8f ", sol[index[i]]);
    }
    printf("\n");

    return 0;
}
