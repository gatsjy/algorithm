#include <bits/stdc++.h>

using namespace std;

int n,m, a[11],cnt = 0;

void DFS(int L, int sum) {
	if (L == n + 1) {
		if (sum == m) {
			cnt++;
		}
	}
	else {
		//cout << sum << endl;
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum - a[L]);
		DFS(L + 1, sum);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	DFS(1, 0);
	cout << cnt;
}