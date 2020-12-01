#include <bits/stdc++.h>

using namespace std;

namespace _1182 {
	int a[30];
	int N, S;
	int cnt = 0;
	void dfs(int cur, int sum) {
		if (cur == N) {
			if (sum == S) cnt++;
			return;
		}
		dfs(cur + 1, sum + a[cur]);
		dfs(cur + 1, sum);
	}
	int main() {
		cin >> N >> S;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		dfs(0, 0);
		if (S == 0) cnt--;
		cout << cnt;
		return 0;
	}
}