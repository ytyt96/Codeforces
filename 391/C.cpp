#include <bits/stdc++.h>

using namespace std;

#define MODULO (1000000000 + 7)

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    default_random_engine engine;
    uniform_int_distribution<long long> distro(LLONG_MIN, LLONG_MAX);
    
    vector<long long> master(m + 1, 0);
    int index = 0;
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        unordered_map<int, int> counter;
        for (int j = 0; j < m; j++) {
            int p;
            scanf("%d", &p);
            counter[p]++;
        }
        
        unordered_map<int, unordered_set<int>> local;
        for (auto it = counter.begin(); it != counter.end(); it++)
            local[it->second].insert(it->first);


        for (auto it = local.begin(); it != local.end(); it++) {
            long long rn = distro(engine);
            for (int p : it->second)
                master[p] ^= rn;
        }
    }

    vector<long long> factorial(6000000);
    factorial[0] = 1;
    for (int i = 1; i < 6000000; i++)
        factorial[i] = (factorial[i - 1] * i) % MODULO;

    map<long long, int> result;
    for (int i = 1; i <= m; i++)
        result[master[i]]++;

    long long answer = 1;
    for (auto it = result.begin(); it != result.end(); it++) {
        answer = (answer * factorial[it->second]) % MODULO;
    }

    cout << answer << "\n";

	return 0;
}
