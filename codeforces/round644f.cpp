#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define MAX 10+1

int t;
string s[MAX];
int n, m;
vector<int> diff;
vector<int> v;
vector<int> ans;
int flag = 0;

void bf(int idx) {
	if (flag == 1) {
		return;
	}
	if (idx == m) {
		flag = 1;
		for (int i = 0; i < v.size(); i++) {
			ans.push_back(v[i]);
		}
		return;
	}
	for (int i = 0; i < 26; i++) {
		int tmpflag = 0;
		for (int j = 0; j < n; j++) {
			if ((char)(i + 'a') != s[j][idx]) {
				diff[j]++;
				if (diff[j] > 1) tmpflag = 1;
			}
		}
		if (tmpflag == 0) {
			v.push_back(i);
			bf(idx + 1);
			v.pop_back();
		}
		for (int j = 0; j < n; j++) {
			if ((char)(i + 'a') != s[j][idx]) {
				diff[j]--;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			diff.push_back(0);
		}
		flag = 0;
		bf(0);
		if (ans.empty()) {
			cout << -1 << "\n";
		}
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << (char)(ans[i] + 'a');
			}
			cout << "\n";
		}
		v.clear();
		ans.clear();
		diff.clear();
	}

	return 0;
}