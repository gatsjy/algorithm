#include <bits/stdc++.h>

namespace _69 {
	using namespace std;

	int front = -1, back = -1, ch[10];
	vector<int> m[10];
	queue<int> q;

	int main() {
		int i, a, b, x;
		for (int i = 1; i <= 6; i++) {
			cin >> a >> b;
			m[a].push_back(b);
			m[b].push_back(a);
		}

		q.push(1);
		ch[1] = 1;
		while (!q.empty()) {
			x = q.front();
			q.pop();
			cout << x << " ";
			for (i = 0; i < m[x].size(); i++) {
				if (ch[m[x][i]] == 0) {
					ch[m[x][i]] = 1;
					q.push(m[x][i]);
				}
			}
		}
		return 0;
	}
}
