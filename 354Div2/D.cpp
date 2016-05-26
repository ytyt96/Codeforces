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
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<ii, int>> iiii;

char laby[1005][1005];
bool dir[1005][1005][4][4];
int n, m;

void getDir(){
	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++){
			switch (laby[r][c]){
				case '+':
					dir[r][c][0][0] = dir[r][c][0][1] = dir[r][c][0][2] = dir[r][c][0][3] = true;
					break;
				case '-':
					dir[r][c][0][0] = dir[r][c][0][2] = true;
					break;
				case '|':
					dir[r][c][0][1] = dir[r][c][0][3] = true;
					break;
				case '^':
					dir[r][c][0][1] = true;
					break;
				case '>':
					dir[r][c][0][2] = true;
					break;
				case '<':
					dir[r][c][0][0] = true;
					break;
				case 'v':
					dir[r][c][0][3] = true;
					break;
				case 'L':
					dir[r][c][0][1] = dir[r][c][0][2] = dir[r][c][0][3] = true;
					break;
				case 'R':
					dir[r][c][0][0] = dir[r][c][0][1] = dir[r][c][0][3] = true;
					break;
				case 'U':
					dir[r][c][0][0] = dir[r][c][0][2] = dir[r][c][0][3] = true;
					break;
				case 'D':
					dir[r][c][0][0] = dir[r][c][0][1] = dir[r][c][0][2] = true;
					break;
				case '*':
					break;
			}

			for (int i = 1; i < 4; i++){
				for (int j = 0; j < 4; j++)
					dir[r][c][i][(i + j) % 4] = dir[r][c][0][j];
			}

		}
}

int main(){
	cin >> n >> m;

	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> laby[i][j];

	int xt, yt, xm, ym;
	cin >> xt >> yt >> xm >> ym;
	xt--;
	yt--;
	xm--;
	ym--;

	getDir();
	
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
	dist[xt][yt][0] = 0;

	queue<iiii> pq;
	pq.push({0, {{xt, yt}, 0}});

	int answer = INT_MAX;
	int go[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	while (!pq.empty()){
		iiii front = pq.front();
		pq.pop();
		int curr_dist = front.first;
		int r = front.second.first.first;
		int c = front.second.first.second;
		int ori = front.second.second;
		if (curr_dist > dist[r][c][ori])
			continue;

		if (r == xm && c == ym)
			break;

		for (int i = 0; i < 4; i++){
			if (!dir[r][c][ori][i])
				continue;

			int new_r = r + go[i][0];
			int new_c = c + go[i][1];
			if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m){
				if (!dir[new_r][new_c][ori][(i + 2) % 4])
					continue;
				if (curr_dist + 1 < dist[new_r][new_c][ori]){
					dist[new_r][new_c][ori] = curr_dist + 1;
					pq.push({dist[new_r][new_c][ori], {{new_r, new_c}, ori}});
				}
			}
		}
		ori = (ori + 1) % 4;
		if (curr_dist + 1 < dist[r][c][ori]){
			dist[r][c][ori] = curr_dist + 1;
			pq.push({dist[r][c][ori], {{r, c}, ori}});
		}
	}
	answer = min(min(dist[xm][ym][0], dist[xm][ym][1]), min(dist[xm][ym][2], dist[xm][ym][3]));
	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;
	cout << "\n";

	return 0;
}
