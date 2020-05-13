#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<string> v;
		int cnt = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '0') continue;
			else {
				string tmp;
				tmp.push_back(s[i]);
				for (int j = 0; j < s.length() - 1 - i; j++) {tmp.push_back('0');}
				v.push_back(tmp);
			}
		}
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";
	}
	return 0;
}