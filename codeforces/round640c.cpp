#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define ll long long

int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		ll n, k;
		scanf("%lld %lld", &n, &k);
		if (k % (n - 1) == 0) {printf("%lld\n", n * (k / (n - 1))-1);}
		else {printf("%lld\n", n * (k / (n - 1))+(k%(n-1)));}
	}
	return 0;
}