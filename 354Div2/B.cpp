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

#define EPS 1e-6

using namespace std;

int main(){
	int n, t;
	cin >> n >> t;

	vector<vector<double>> liquid(n, vector<double>(n, 0));

	for (int i = 0; i < t; i++){
		liquid[0][0] += 1;
		for (int j = 1; j < n; j++){
			if (liquid[j - 1][0] > 1)
				liquid[j][0] += (liquid[j - 1][0] - 1) / 2;
			for (int k = 1; k < j; k++){
				if (liquid[j - 1][k - 1] > 1)
					liquid[j][k] += (liquid[j - 1][k - 1] - 1) / 2;
				if (liquid[j - 1][k] > 1)
					liquid[j][k] += (liquid[j - 1][k] - 1) / 2;
			}
			if (liquid[j - 1][j - 1] > 1)
				liquid[j][j] += (liquid[j - 1][j - 1] - 1) / 2;
		}
		for (int j = 0; j < n; j++)
			for (int k = 0; k <= j; k++)
				liquid[j][k] = min(liquid[j][k], 1.0);
	}
	int answer = 0;
	for (int j = 0; j < n; j++)
		for (int k = 0; k <= j; k++)
			if (liquid[j][k] >= 1)
				answer++;	
	cout << answer << '\n';	
	return 0;
}
