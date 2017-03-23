#include <bits/stdc++.h>

using namespace std;

bool visited[400][400][30][8];
int walk[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0},
                  {-1, -1}, {0, -1}, {1, -1}};
bool fire[400][400];

int n;
int t[40];

void sim(int x, int y, int level, int dir) {
    if (level == n)
        return;

    if (visited[x][y][level][dir])
        return;
    visited[x][y][level][dir] = true;

    fire[x][y] = true;
    for (int i = 0; i < t[level] - 1; i++) {
        x += walk[dir][0];
        y += walk[dir][1];
        fire[x][y] = true;
    }
    int dir1 = (dir - 1 + 8) % 8;
    int dir2 = (dir + 1) % 8;
    sim(x + walk[dir1][0], y + walk[dir1][1], level + 1, dir1);
    sim(x + walk[dir2][0], y + walk[dir2][1], level + 1, dir2);
}

int main(){
    memset(visited, 0, sizeof visited);
    memset(fire, 0, sizeof fire);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    sim(200, 200, 0, 2);

    int sol = 0;

    for (int i = 0; i < 400; i++) 
        for (int j = 0; j < 400; j++)
            if (fire[i][j])
                sol++;
    printf("%d\n", sol);
	return 0;
}
