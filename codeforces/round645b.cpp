#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

int t;

int main(void) {
	scanf("%d", &t);
	int n;
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int tmp;
		vector<int> v;
		multiset<int> s;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
			s.insert(tmp);
		}
		sort(v.begin(), v.end());
		int cnt = 1;
		for (int i = n-1; i >= 0; i--) {
			if (v[i] <= i + 1) {
				cnt = i + 2;
				break;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}