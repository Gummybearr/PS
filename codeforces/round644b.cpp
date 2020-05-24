#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 50+1

int t;
int a[MAX];

int main() {
	scanf("%d", &t);
	int n;
	while (t--) {
		fill(a, a + MAX, 0);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int ans = abs(a[0] - a[n - 1]);
		for (int i = 1; i < n; i++) {
			ans = min(ans, abs(a[i] - a[i - 1]));
		}
		printf("%d\n", ans);
	}

	return 0;
}