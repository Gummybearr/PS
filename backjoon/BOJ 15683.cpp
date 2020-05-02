#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define MAX 8+1

int n, m, ans = 100;
vector <pair<int, int>> v;
int board[MAX][MAX], visit[MAX][MAX];
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
//1~5 cctv
//1: one, 2: two, but 180, 3: two, but 90, 4: three, 5: all
//6: wall

void countit() {
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (visit[i][j] == 0) cnt++;
	ans = min(ans, cnt);
}

void shoot(int idx, int dir, int flag) {
	int y = v[idx].first, x = v[idx].second;
	int ty = y, tx = x;
	while (true) {
		ty = ty + dy[dir], tx = tx + dx[dir];
		if (ty < 0 || ty >= n || tx < 0 || tx >= m) break;
		if (visit[ty][tx] == -1) break;
		visit[ty][tx]+=1*flag;
	}
}

void bf(int idx) {
	if (idx == v.size()) { countit();	return; }
	int y = v[idx].first, x = v[idx].second;
	if (board[y][x] == 1) 
		for (int i = 0; i < 4; i++) {
			shoot(idx, i, 1);
			bf(idx + 1);
			shoot(idx, i, -1);
		}
	else if (board[y][x] == 2) 
		for (int i = 0; i < 2; i++) {
			shoot(idx, i, 1);	shoot(idx, i + 2, 1);
			bf(idx + 1);
			shoot(idx, i, -1);	shoot(idx, i + 2, -1);
		}
	else if (board[y][x] == 3) 
		for (int i = 0; i < 4; i++) {
			shoot(idx, i % 4, 1);	shoot(idx, (i + 1) % 4, 1);
			bf(idx + 1);
			shoot(idx, i % 4, -1);	shoot(idx, (i + 1) % 4, -1);
		}
	else if (board[y][x] == 4) 
		for (int i = 0; i < 4; i++) {
			shoot(idx, i % 4, 1);	shoot(idx, (i + 1) % 4, 1);	shoot(idx, (i + 2) % 4, 1);
			bf(idx + 1);
			shoot(idx, i % 4, -1);	shoot(idx, (i + 1) % 4, -1);	shoot(idx, (i + 2) % 4, -1);
		}
	else if (board[y][x] == 5) {
		shoot(idx, 0, 1);	shoot(idx, 1, 1);	shoot(idx, 2, 1);	shoot(idx, 3, 1);
		bf(idx + 1);
		shoot(idx, 0, -1);	shoot(idx, 1, -1);	shoot(idx, 2, -1);	shoot(idx, 3, -1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) continue;
			if (board[i][j] == 6) visit[i][j] = -1;
			else { visit[i][j] = 100;	v.push_back({ i,j }); }
		}
	bf(0);
	printf("%d\n", ans);
	return 0;
}