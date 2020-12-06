#include <bits/stdc++.h>

using namespace std;

namespace _12851 {
	int ch[100001];
	int n, k;
	int cnt = 0;
	int minsec = 0;

	int bfs(int n, int k) {
		queue<pair<int, int>> q;
		ch[n] = 1;
		q.push({ n,0 });

		while (!q.empty()) {
			int curpos = q.front().first;
			int cursec = q.front().second;
			q.pop();

			if (minsec && curpos == k && minsec == cursec) {
				cnt++;
			}

			if (!minsec && curpos == k) {
				minsec = cursec;
				cnt++;
			}
			// 다음까지 넘어와서 다 확인하고 ch를 체크한다.
			ch[curpos] = 1;

			for (auto next : { curpos + 1, curpos - 1, curpos * 2 }) {
				if (next < 0 || next > 100000) continue;
				if (ch[next]) continue;
				q.push({ next, cursec + 1 });
			}
		}
		return minsec;
	}

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);

		cin >> n >> k;

		cout << bfs(n, k) << "\n";
		cout << cnt << "\n";

		return 0;
	}
}