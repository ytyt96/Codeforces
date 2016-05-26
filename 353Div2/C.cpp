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

int go_next(int curr, int n){
	return (curr + 1) % n;
}

int go_prev(int curr, int n){
	return (curr + n - 1) % n;
}

int main(){
	int n;
	cin >> n;
	vector<long long> bank(n);
	int index = -1;
	bool work = false;
	for (int i = 0; i < n; i++){
		cin >> bank[i];
		if (bank[i] != 0)
			work = true;
	}

	if (!work){
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (bank[i] != 0 && bank[go_prev(i, n)] == 0)
			index = i;

	if (index == -1)
		index = 0;
		
	int curr = index;
	auto temp = bank;
	int best_op = n * 10;
	int curr_op = 0;

	do{
			temp[go_next(curr, n)] += temp[curr];
			temp[curr] = 0;
			curr = go_next(curr, n);
			curr_op++;
			while (temp[curr] == 0 && curr != index)
					curr = go_next(curr, n);
	}while (curr != index);
	best_op = min(best_op, curr_op);

	curr = index;
	temp = bank;
	curr_op = 0;

	do{
			temp[go_prev(curr, n)] += temp[curr];
			temp[curr] = 0;
			curr = go_prev(curr, n);
			curr_op++;
			while (temp[curr] == 0 && curr != index)
					curr = go_prev(curr, n);
	}while (curr != index);
	best_op = min(best_op, curr_op);
	cout << best_op << "\n";

	return 0;
}
