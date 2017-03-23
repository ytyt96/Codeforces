#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> primes;
map<int, int> counter;

#define UPPERBOUND 100050

void sieve() {
    bitset<UPPERBOUND> bs;
    bs.set();
    bs[0] = bs[1] = false;
    for (long long i = 2; i < UPPERBOUND; i++)
        if (bs[i]) {
            for (long long j = i * i; j < UPPERBOUND; j += i)
                bs[j] = false;
            primes.push_back((int)i);
        }
}

void factorization(int N) {
    long long index = 0, factor = primes[index];
    while (factor * factor <= N) {
        if (N % factor == 0)
            counter[factor]++;
        while (N % factor == 0) {
            N /= factor;
        }
        factor = primes[++index];
    }

    if (N != 1)  {
        counter[N]++;
    }
}

int main(){
    sieve();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        factorization(num);
    }

    int answer = 1;
    for (auto it = counter.begin(); it != counter.end(); it++)
        answer = max(answer, it->second);
    printf("%d\n", answer);
	return 0;
}
