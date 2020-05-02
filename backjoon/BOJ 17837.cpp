#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define MAX 12+1

struct player {int y, x, dir;};
struct chess { int color=0; deque<int> d; }; //0: W 1: R 2: B
int n, k, cnt = 0, flag = 0;
chess board[MAX][MAX];
player mal[MAX];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };

bool check() {
	int y = mal[0].y, x = mal[0].x;
	for (int i = 1; i < k; i++) 
		if (y != mal[i].y || x != mal[i].x) return false;
	return true;
}

void move() {
	for (int a = 0; a < k; a++) {
		int ty = mal[a].y+dy[mal[a].dir], tx = mal[a].x+dx[mal[a].dir];
		//turn direction in case it goes out
		if (ty < 0 || ty >= n || tx < 0 || tx >= n) {
			mal[a].dir = (mal[a].dir < 2) ? (mal[a].dir==1?0:1) : (mal[a].dir==2?3:2);
			ty = mal[a].y + dy[mal[a].dir], tx = mal[a].x + dx[mal[a].dir];
			if (board[ty][tx].color == 2) continue;
		}
		//moving to blue
		else if (board[ty][tx].color == 2) {
			mal[a].dir = (mal[a].dir < 2) ? (mal[a].dir == 1 ? 0 : 1) : (mal[a].dir == 2 ? 3 : 2);
			ty = mal[a].y + dy[mal[a].dir], tx = mal[a].x + dx[mal[a].dir];
			if (board[ty][tx].color == 2) continue;
			if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
		}
		deque<int> pred;
		while (!board[mal[a].y][mal[a].x].d.empty()) {
			int val = board[mal[a].y][mal[a].x].d.back();
			board[mal[a].y][mal[a].x].d.pop_back();
			pred.push_back(val);
			if (val == a) break;
		}
		//moving to white
		if (board[ty][tx].color == 0) {
			while (!pred.empty()) {
				board[ty][tx].d.push_back(pred.back());
				mal[pred.back()].y = ty;
				mal[pred.back()].x = tx;
				pred.pop_back();
			}
		}
		//moving to red
		else if (board[ty][tx].color == 1) {
			while (!pred.empty()) {
				board[ty][tx].d.push_back(pred.front());
				mal[pred.front()].y = ty;
				mal[pred.front()].x = tx;
				pred.pop_front();
			}
		}
		if (board[ty][tx].d.size() > 3) { flag = 1;	return; }
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &board[i][j].color);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &mal[i].y, &mal[i].x, &mal[i].dir);
		mal[i].y--;	mal[i].x--;	mal[i].dir--;
		board[mal[i].y][mal[i].x].d.push_back(i);
	}
	while (cnt<=1000 && flag == 0) {
		if (check() == true) break;
		move();
		cnt++;
	}
	printf("%d\n", cnt > 1000 ? -1 : cnt);
	return 0;
}