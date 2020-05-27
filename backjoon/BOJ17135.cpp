#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 16+1
#define piii pair<pair<int, int>, pair<int, int>>

int n, m, d;
int board[MAX][MAX];
int origin_board[MAX][MAX];
int gmax = 0, lmax = 0;
int archers[MAX];
vector<int> v;
int dy[] = { 0,-1,0 }, dx[] = { -1,0,1 };

bool mapcheck() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { if (board[i][j] == 1) return true; }
	}
	return false;
}

void settarget() {
	queue<piii> q;
	for (int i = 0; i < 3; i++) { q.push({ {n, v[i]}, {v[i], 0} }); }
	int dup[MAX];
	fill(dup, dup + MAX, 0);
	while (!q.empty()) {
		auto tmp = q.front();
		//printf("y: %d \tx: %d \t archer: %d \t dist: %d\n", tmp.first.first, tmp.first.second, tmp.second.first, tmp.second.second);
		q.pop();
		if (tmp.second.second >= d) continue;
		if (dup[tmp.second.first] == 1) continue;
		for (int i = 0; i < 3; i++) {
			int ty = tmp.first.first + dy[i], tx = tmp.first.second + dx[i];
			if (ty < 0 || ty>=n || tx < 0 || tx >= m) continue;
			if (board[ty][tx] > 0) {
				dup[tmp.second.first] = 1;
				board[ty][tx] = 2;
				break;
			}
			else {
				q.push({ { ty, tx }, { tmp.second.first, tmp.second.second + 1 } });
			}
		}

	}
}

void shoot() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 2) { board[i][j] = 0;	lmax++; }
		}
}

void enemymove() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			if (i != n - 1) { board[i + 1][j] = board[i][j]; }
			board[i][j] = 0;
		}
	}
}

void setmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = origin_board[i][j];
		}
	}
}

void simul() {
	lmax = 0;
	setmap();
	while (mapcheck()) {
		//printf("enemy exists so lets go\n");
		settarget();
		shoot();
		enemymove();
	}
	gmax = max(gmax, lmax);
}

void bf(int idx, int cnt) {
	if (idx >= m) return;
	if (cnt == 3) { simul();	return; }
	v.push_back(idx+1);
	bf(idx + 1, cnt + 1);
	v.pop_back();

	bf(idx + 1, cnt);
}

int main(void) {
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + MAX, 0);
		for (int j = 0; j < m; j++) { scanf("%d", &origin_board[i][j]); }
	}
	fill(archers, archers + MAX, 0);
	bf(-1, 0);
	printf("%d\n", gmax);
	return 0;
}