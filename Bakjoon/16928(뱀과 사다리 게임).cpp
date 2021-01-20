#include <bits/stdc++.h>

using namespace std;

int dp[101];
queue<pair<int,int>> q;
map<int, int> mm;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= 100; i++) {
		dp[i] = 2147000000;
	}

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mm[a] = b;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mm[a] = b;
	}

	q.push({ 1,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (mm[cur] > 0) {
			cur = mm[cur];
		}
		if (cur == 100) {
			cout << dp[100];
			return 0;
		}
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next > 100) continue;
			if (dp[next] != 2147000000 && dp[next] > 0)continue;
			q.push({ next,cnt + 1 });
			dp[next] = min(dp[next], cnt + 1);
		}
	}

	return 0;
}