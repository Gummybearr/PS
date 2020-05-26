#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define ll long long

int t;

int main(void) {
	scanf("%d", &t);
	ll fy, fx, ty, tx;
	while (t--) {
		scanf("%lld %lld %lld %lld", &fy, &fx, &ty, &tx);
		ll ry = ty - fy, rx = tx - fx;
		printf("%lld\n", ry * rx + 1);
	}
	return 0;
}