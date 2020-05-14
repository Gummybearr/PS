#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define pii pair<int, int>

int t, n;
int num[1 << 20];

struct cmp {
	bool operator()(pair<int, pii> a, pair<int, pii> b) {
		return a.first == b.first ? a.second.first>b.second.first : a.first<b.first;
	}
};

int main() {
	scanf("%d ", &t);
	while (t--) {
		scanf("%d", &n);
		fill(num, num + (1 << 20), 0);
		priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> pq;
		pq.push({ n, {0,n - 1} });
		for(int i = 0;i<n;i++) {
			if (pq.empty()) break;
			auto it = pq.top();
			int l = it.second.first, r = it.second.second;
			pq.pop();
			int tval = (l + r) >> 1;
			num[tval] = i + 1;
			if(l<=tval-1)	pq.push({ tval - l+1, {l,tval - 1} });
			if (r>=tval + 1)	pq.push({ r - tval+1, {tval + 1, r} });
		}
		for (int i = 0; i < n; i++) { printf("%d ", num[i]); }	printf("\n");
	}
	return 0;
}