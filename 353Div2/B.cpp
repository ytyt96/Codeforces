#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
#include <utility>
#include <random>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

int main(){
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	unsigned long long answer = 0;

	for (int i = 1; i <= n; i++){
		int c1 = a + b + i;
		int c2 = a + c + i;
		int c3 = b + d + i;
		int c4 = c + d + i;
		int ma = max(max(c1, c2), max(c3, c4));
		int mi = min(min(c1, c2), min(c3, c4));
		if (ma + 1 - mi >= 1){
			if (n - (ma + 1 - mi) + 1 > 0)
				answer += (n - (ma + 1 - mi) + 1);
		}
		
	}

	cout << answer << "\n";
	return 0;
}
