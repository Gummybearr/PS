#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define ll long long

int t, n;
int num[1<<20];
priority_queue <pair<int, pair<int, int>>> q;

int main() {
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		q.push({ n,{-1,n} });
		for (int i = 1; i <= n; i++) {
			auto it = q.top();
			q.pop();
			int l = -it.second.first, r = it.second.second;
			int tval = (l + r) >> 1;
			num[tval] = i;
			if (tval - 1 - l + 1 > 0) q.push({ tval - 1 - l + 1,{-l,tval - 1} });
			if (r - tval > 0) q.push({ r - tval,{-tval - 1,r} });
		}
		for (int i = 1; i <= n; i++) printf("%d ", num[i]);	printf("\n");
	}
}