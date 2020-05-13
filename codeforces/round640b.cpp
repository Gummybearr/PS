#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)

int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		if (k > n) {printf("NO\n");	continue;}
		if (n % 2 != k % 2) {
			if (k * 2 > n) {printf("NO\n");	continue;}
			if (n % 2 == 1) {printf("NO\n");	continue;}
			else {
				printf("YES\n");
				for (int i = 1; i < k; i++) {printf("2 ");	n -= 2;}
				printf("%d\n", n);
				continue;
			}
		}
		printf("YES\n");
		for (int i = 1; i < k; i++) {printf("1 ");	n -= 1;}
		printf("%d\n", n);
		continue;
	}
	return 0;
}