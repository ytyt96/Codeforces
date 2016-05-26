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
	int n;
	cin >> n;
	vector<int> nums(n);
	int small, large;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
		if (nums[i] == 1)
			small = i;
		if (nums[i] == n)
			large = i;
	}

	cout << max(max(abs(0 - large), abs(0 - small)), max(abs(n - 1 - large), abs(n - 1 - small))) << "\n";

	return 0;
}
