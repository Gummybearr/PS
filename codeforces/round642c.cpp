#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define ll long long

int t, n;
ll dp[5 * (ll)1e5 + 1];

int main() {
	dp[3] = 8;
	for (ll i = 5; i <= 500000; i += 2) dp[i] = dp[i - 2] + (i - 1) * 4 * (i / 2);
	scanf("%d ", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}