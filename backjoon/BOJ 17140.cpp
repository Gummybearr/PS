#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define MAX 100+1
#define pii pair<int, int>

int r, c, k, timecnt;
int board[MAX][MAX];
int rc, cc;

bool cmp(pii a, pii b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else return false;
}

void simul1() {
	//printf("simul1 called\n");
	int cval = cc;
	cc = 0;
	for (int i = 0; i < rc; i++) {
		map<int, int> m;
		for (int j = 0; j < cval; j++) {
			if (board[i][j] == 0) continue;
			auto it = m.find(board[i][j]);
			if (it == m.end()) { m.insert({ board[i][j], 1 }); }
			else { it->second++; }
		}
		vector<pii> v;
		for (auto it : m) { v.push_back({ it.first, it.second }); }
		sort(v.begin(), v.end(), cmp);
		int idx = 0;
		fill(board[i], board[i] + MAX, 0);
		for (int j = 0; j < v.size(); j++) {
			//printf("nums[%d]: %d\n", j, nums[j]);
			board[i][idx] = v[j].first;
			board[i][idx + 1] = v[j].second;
			idx += 2;
		}
		cc = max(idx, cc);
	}
}

void simul2() {
	//printf("simul2 called\n");
	int rval = rc;
	rc = 0;
	for (int j = 0; j < cc; j++) {
		map<int, int> m;
		for (int i = 0; i < rval; i++) {
			if (board[i][j] == 0) continue;
			auto it = m.find(board[i][j]);
			if (it == m.end()) { m.insert({ board[i][j], 1 }); }
			else { it->second++; }
		}
		vector<pii> v;
		for (auto it : m) { v.push_back({ it.first, it.second }); }
		sort(v.begin(), v.end(), cmp);
		int idx = 0;
		for (int i = 0; i < MAX; i++) board[i][j] = 0;
		for (int i = 0; i < v.size(); i++) {
			//printf("nums[%d]: %d\n", j, nums[j]);
			board[idx][j] = v[i].first;
			board[idx + 1][j] = v[i].second;
			idx += 2;
		}
		rc = max(idx, rc);
	}
}

void simul() {
	//printf("rc: %d\tcc: %d\n", rc, cc);
	(rc >= cc) ? simul1() : simul2();
	/*
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < cc; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	*/
	timecnt++;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < MAX; i++) fill(board[i], board[i] + MAX, 0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	rc = cc = 3;
	timecnt = 0;
	while (board[r - 1][c - 1] != k) {
		//printf("board[%d][%d]: %d\n", r - 1, c - 1, board[r - 1][c - 1]);
		if (timecnt > 100) break;
		simul();
	}
	printf("%d", timecnt > 100 ? -1 : timecnt);
	return 0;
}