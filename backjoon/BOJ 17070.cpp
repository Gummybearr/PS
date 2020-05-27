#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 16+1

int n, cnt = 0;
int house[MAX][MAX];
int dy[] = { 0,1,1 }, dx[] = { 1,1,0 };

void bf(int y, int x, int dir) {
	if (y == n - 1 && x == n - 1) { cnt++;	return; }
	for (int i = 0; i < 3; i++) {
		if (abs(dir - i) == 2) continue;
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
		if (i == 0) { if (house[ty][tx] == 1 || house[ty][tx - 1] == 1) continue; }
		else if (i == 1) { if (house[ty][tx] == 1 || house[ty][tx - 1] == 1 || house[ty - 1][tx] == 1) continue; }
		else { if (house[ty][tx] == 1 || house[ty - 1][tx] == 1) continue; }
		bf(ty, tx, i);
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {scanf("%d", &house[i][j]);}
	}
	bf(0, 1, 0);
	printf("%d\n", cnt);
	return 0;
}