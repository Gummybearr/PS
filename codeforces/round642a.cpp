#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)

int t, n, m;

int main() {
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		if (n == 1) { printf("0\n");	continue; }
		else if (n == 2) { printf("%d\n", m); continue; }
		else { printf("%d\n", m * 2); continue; }
	}
	return 0;
}