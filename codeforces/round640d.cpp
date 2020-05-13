#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable: 4996)

int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		deque<int> d;
		int n;
		scanf("%d", &n);
		while (n--) {
			int tmp;
			scanf("%d", &tmp);
			d.push_back(tmp);
		}
		int ngame = 0;
		int alice = 0, bob = 0;
		int acum = 0, aliceacum = 0, bobacum = 0;
		int flag = 0; //alice and bob
		while (!d.empty()) {
			if (flag == 0) {
				//printf("alice turn!\n");
				ngame++;
				while (!d.empty()) {
					//printf("alice eats %d cuz alice has %d\tacum: %d\n", d.front(), aliceacum, acum);
					aliceacum += d.front();
					alice += d.front();
					d.pop_front();
					if (aliceacum > acum) {
						acum = max(aliceacum, acum);
						flag = 1;
						aliceacum = 0;
						break;
					}
				}
			}
			else {
				//printf("bob turn!\n");
				ngame++;
				while (!d.empty()) {
					//printf("bob eats %d cuz bob has %d\tacum: %d\n", d.back(), bobacum, acum);
					bobacum += d.back();
					bob+=d.back();
					d.pop_back();
					if (bobacum > acum) {
						acum = max(bobacum, acum);
						flag = 0;
						bobacum = 0;
						break;
					}
				}
			}
		}
		printf("%d %d %d\n", ngame, alice, bob);
	}
	return 0;
}