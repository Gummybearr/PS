#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define ll long long

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll ans = (ll)pow(2, n + 1) - (2 * (ll)(pow(2, n) - (ll)pow(2, n / 2))) - 2;
		printf("%lld\n", ans);
	}
	return 0;
}