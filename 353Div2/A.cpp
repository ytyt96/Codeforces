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
	int a, b, c;
	cin >> a >> b >> c;

	if (c == 0){
		if (a == b)
			cout << "YES\n";
		else
			cout << "NO\n";
		return 0;
	}
	else{
		if ((b - a) % c == 0 && (b - a) / c >= 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
	return 0;

}
