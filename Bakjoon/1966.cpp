#include <bits/stdc++.h>

using namespace std;
struct print {
	int idx;
	int point;
	print(int a, int b) {
		idx = a;
		point = b;
	}
	bool operator<(const print& b) const {
		if (point == b.point) {
			return idx > b.idx;
		}
		else {
			return point > b.point;
		}
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		priority_queue<print> pq;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			pq.push(print(i, a));
		}
		int cnt = 1;
		while (!pq.empty()) {
			if (pq.top().idx == m) {
				cout << cnt << "\n";
				break;
			}
			else {
				cnt++;
				pq.pop();
			}
		}
	}
	return 0;
}