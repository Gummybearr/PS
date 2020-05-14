#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define ll long long

int t, n, k;

int main() {
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		priority_queue<int, vector<int>, greater<int>> a;
		priority_queue<int> b;
		int tmp;
		for (int i = 0; i < n; i++) { scanf("%d", &tmp);	a.push(tmp); }
		for (int i = 0; i < n; i++) { scanf("%d", &tmp);	b.push(tmp); }
		while (k--) {
			if (a.top() >= b.top()) break;
			a.push(b.top());	b.pop();
			b.push(a.top());	a.pop();
		}
		ll ans = 0;
		while (!a.empty()) {ans += a.top();	a.pop();}
		printf("%lld\n", ans);
	}
	return 0;
}