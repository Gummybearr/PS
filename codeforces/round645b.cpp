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
		int notyet = 0;
		for (int i = 0; i < v.size(); i++) {
			//printf("i: %d \tcnt: %d \tnotyet: %d\n", i, cnt, notyet);
			if (s.count(v[i]) - 1 + cnt >= v[i]) {
				//printf("%dth granny can join\n", i);
				cnt++;
				notyet = 0;
			}
			else {
				if (s.count(v[i]) - 1 + cnt + notyet >= v[i]) {
					//printf("%dth granny made it possible\n", i);
					cnt += notyet;
					notyet = 0;
					cnt++;
				}
				else {
					//printf("%dth granny cannot join\n", i);
					notyet += s.count(v[i]);
					i += s.count(v[i]) - 1;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}