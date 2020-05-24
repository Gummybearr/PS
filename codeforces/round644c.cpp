#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 50+1

int t, odd, even;
int a[MAX];

int main() {
	scanf("%d", &t);
	int n;
	while (t--) {
		scanf("%d", &n);
		odd = even = 0;
		set<int> s;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			s.insert(a[i]);
			if (a[i] % 2 == 0) {
				even++;
			}
			else {
				odd++;
			}
		}
		if (odd % 2 == 0) {
			printf("YES\n");
		}
		else {
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (s.count(a[i] - 1) > 0 || s.count(a[i] + 1) > 0) {
					flag = 1;
				}
			}
			if (flag == 1) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}