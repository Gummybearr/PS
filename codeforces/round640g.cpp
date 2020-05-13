#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define ll long long

int t, n;
int visit[1 << 20];
vector<int> v, ans;

void dfs(int idx) {
	if (v.size() == n) {
		for (int i = 0; i < v.size(); i++) {ans.push_back(v[i]);}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!ans.empty()) return;
		if (visit[i] == 1) continue;
		if (!v.empty()) {
			int tval = abs(v[v.size() - 1] - i);
			if (tval < 2 || tval>4) continue;
		}
		visit[i] = 1;
		v.push_back(i);
		dfs(i);
		v.pop_back();
		visit[i] = 0;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		fill(visit, visit + (1 << 20), 0);
		dfs(0);
		v.clear();
		if (ans.empty()) {printf("-1\n");	continue;}
		for (int i = 0; i < ans.size(); i++) {printf("%d ", ans[i]);}
		printf("\n");
		ans.clear();
	}
	return 0;
}