#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 50+1

int t;
char board[MAX][MAX];
int visit[MAX][MAX];
int dy[] = { 0,-1 }, dx[] = { -1,0 };

int main() {
	scanf("%d", &t);
	int n;
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < MAX; i++) {
			fill(board[i], board[i] + MAX, '0');
			fill(visit[i], visit[i] + MAX, 0);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1s", &board[i][j]);
			}
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < n - 1; i++) {
			if (board[i][n - 1] == '1') {
				if (visit[i][n - 1] == 1) continue;
				visit[i][n - 1] = 1;
				q.push({ i,n - 1 });
			}
		}
		for (int j = 0; j < n; j++) {
			if (board[n - 1][j] == '1') {
				if (visit[n - 1][j] == 1) continue;
				visit[n - 1][j] = 1;
				q.push({ n - 1, j });
			}
		}
		while (!q.empty()) {
			auto tmp = q.front();
			q.pop();
			for (int i = 0; i < 2; i++) {
				int ty = tmp.first + dy[i], tx = tmp.second + dx[i];
				if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
				if (visit[ty][tx] == 1) continue;
				if (board[ty][tx] == '1') {
					visit[ty][tx] = 1;
					q.push({ ty, tx });
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//printf("%d ", visit[i][j]);
				if (board[i][j] == '1' && visit[i][j] == 0) {
					flag = 1;
				}
			}
			//printf("\n");
		}
		printf("%s\n", flag == 1 ? "NO" : "YES");
	}

	return 0;
}