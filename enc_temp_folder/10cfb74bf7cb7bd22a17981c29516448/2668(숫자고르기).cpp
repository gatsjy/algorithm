#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<int> res;
vector<int> ch;

int dfs(int idx) {
	ch[idx] = 1;
	int next = a[idx];
	if (!ch[next]) {
		return dfs(next);
	}
	return next;
}

int main() {
	cin >> n;

	a.resize(n + 1);
	res.resize(n + 1); // 해당 값이 선택될것인지 아닌지 체크하는 배열
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		ch.clear();
		ch.resize(n + 1, 0);
		//cout << dfs(i) << " ";
		if (i == dfs(i)) {
			res[i] = 1;
			cnt++;
		}
	}

	cout << cnt << "\n";
	for (int i = 1; i <= n; i++) {
		if (res[i] == 1) {
			cout << i << " ";
		}
	}

	return 0;
}