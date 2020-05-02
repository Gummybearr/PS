#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define MAX 30+2

int n, m, h, a, b, ans = 5;
int board[MAX][MAX], dir[MAX][MAX];
vector<pair<int, int>> v;

bool simul() {
	for (int i = 1; i <= n; i++) {
		int val = i, cur = i;
		for (int j = 1; j <= h; j++) {
			if (board[j][cur] == 0) continue; 
			cur = (dir[j][cur] == 1) ? cur + 1 : cur - 1;
		}
		if (cur != val) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (ans <= cnt) return;
	if (simul() == true) { ans = min(ans, cnt);	return; }
	if (idx >= v.size() || cnt>=3) return;
	for (int i = idx; i < v.size(); i++) {
		if (board[v[i].first][v[i].second] + board[v[i].first][v[i].second - 1] > 0) continue;
		board[v[i].first][v[i].second] = board[v[i].first][v[i].second - 1] = 1;
		dir[v[i].first][v[i].second] = -1;	dir[v[i].first][v[i].second - 1] = 1;
		dfs(i + 1, cnt + 1);
		dir[v[i].first][v[i].second] = dir[v[i].first][v[i].second - 1] = 0;
		board[v[i].first][v[i].second] = board[v[i].first][v[i].second - 1] = 0;
	}
}

void pickline() {
	for (int i = 1; i <= h; i++) {
		for (int j = 2; j <= n; j++) {
			if (board[i][j] + board[i][j - 1] > 0) continue;
			v.push_back({ i,j });
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < MAX; i++) {
		fill(board[i], board[i] + MAX, 0);
		fill(dir[i], dir[i] + MAX, 0);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		board[a][b] = board[a][b + 1] = 1;
		dir[a][b] = 1;	dir[a][b + 1] = -1;
	}
	pickline();
	dfs(0, 0);
	printf("%d\n", ans > 3 ? -1 : ans);
	return 0;
}