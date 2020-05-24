#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

int t;

int main() {
	scanf("%d", &t);
	int a, b;
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", max(max(a, b) * max(a, b), 4* min(a, b) * min(a, b)));
	}

	return 0;
}