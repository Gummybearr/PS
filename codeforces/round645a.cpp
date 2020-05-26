#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

int t;

int main(void) {
	scanf("%d", &t);
	int n, m;
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", n * m / 2 + n * m % 2);
	}

	return 0;
}