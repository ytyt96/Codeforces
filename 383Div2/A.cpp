#include <bits/stdc++.h>

using namespace std;

#define UPPERBOUND 2000000

bitset<UPPERBOUND> bs;
void sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    for (long long i = 2; i < UPPERBOUND; i++) 
        if (bs[i]) {
            for (long long j = i * i; j < UPPERBOUND; j += i)
                bs[j] = false;
        }
}

int main(){
    int n;
    sieve();
    scanf("%d", &n);
    for (int i = 1; i <= 1000; i++)
        if (!bs[i * n + 1]) {
            printf("%d\n", i);
            break;
        }
    
    return 0;
}
