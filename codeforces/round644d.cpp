#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 50+1

int t;
//31623

int main() {
	scanf("%d", &t);
	int n, k;
	while (t--) {
		scanf("%d %d", &n, &k);
		if (k >= n) {
			printf("1\n");
		}
		else {
			int ans = n;
			for (int i = 2; i <= sqrt(n); i++) {
				if (i > k) continue;
				if (n % i == 0) {
					ans = min(ans, n / i);
					if (n / i <= k) {
						ans = min(ans, i);
					}
				}
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}