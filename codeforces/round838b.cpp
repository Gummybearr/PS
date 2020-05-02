#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)
#define ll long long

int t, n, k, period;
int arr[1 << 20];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		period = 0;
		map<int, int> m;
		int lval = 0;
		for (int i = 0; i < n; i++) { 
			scanf("%d", &arr[i]);	
			lval = max(arr[i], lval);
			auto it = m.find(arr[i]);
			if (it == m.end()) { 
				m.insert({ arr[i], 1 });
				period = max(period, 1);
			}
			else {
				it->second++;
				period = max(period, it->second);
			}
		}
		if (m.size() > k) { printf("-1\n"); continue; }
		vector<int> v;
		int a = 100;
		for (int i = 0; i <100; i++) {
			for (auto val : m) { v.push_back(val.first); }
			for (int j = 0; j < k - m.size(); j++) { v.push_back(lval); }
		}
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++) { printf("%d ", v[i]); }
		printf("\n");
		m.clear();
		v.clear();
	}
	return 0;
}