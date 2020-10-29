#include <bits/stdc++.h>

using namespace std;

namespace _72 {
	int main() {
		queue<int> q;
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			q.push(i);
		}

		int cnt = 0;
		while (!q.empty()) {
			for (int i = 1; i < k; i++) {
				q.push(q.front());
				q.pop();
			}
			q.pop();
			if (q.size() == 1) {
				cout << q.front();
				q.pop();
			}
		}
	}
}
