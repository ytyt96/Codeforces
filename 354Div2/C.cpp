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
	int n, k;
	cin >> n >> k;
	string st;
	cin >> st;

	int s = 0, t = 0;
	int a = 0, b = 0;

	int answer = 1;
	for (t = 0; t < n; t++){
		if (st[t] == 'a')
			a++;
		else
			b++;

		while (min(a, b) <= k && s > 0){
			if (st[s - 1] == 'a')
				a++;
			else
				b++;
			s--;
		}

		while (min(a, b) > k){
			if (st[s] == 'a')
				a--;
			else
				b--;
			s++;
		}

		answer = max(answer, t - s + 1);
	}

	cout << answer << "\n";

	return 0;
}
