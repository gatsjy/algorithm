#include <bits/stdc++.h>

namespace _71 {
	using namespace std;
	int d[3] = { 1,-1,5 };
	int ch[10001];
	int jump = 21470000000;
	int main() {
		int s, e, x, pos;
		cin >> s >> e;
		queue<int> Q;
		Q.push(s);
		ch[s] = 1;
		while (!Q.empty()) {
			x = Q.front();
			Q.pop();
			for (int i = 0; i < 3; i++) {
				pos = x + d[i];
				if (pos <= 0 || pos >= 10000) continue;
				if (pos == e) {
					cout << ch[x];
					return 0;
				}
				if (ch[pos] == 0) {
					ch[pos] = ch[x] + 1;
					Q.push(pos);
				}
			}
		}
		cout << jump;
		return 0;
	}
}
