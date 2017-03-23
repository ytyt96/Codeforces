#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int x;
	scanf("%d", &x);
	vector<int> dp(x + 1, x * 2);
	dp[0] = 0;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= 5; j++)
			if (i - j >= 0 && dp[i - j] + 1 < dp[i])
				dp[i] = dp[i - j] + 1;
	printf("%d\n", dp[x]);
}
