#include <bits/stdc++.h>

namespace _86 {
	using namespace std;

	int n, r;
	int ch[30];

	void dfs(int s, int l) {
		if (l == r) {
			for (int i = 0; i < l; i++) {
				cout << ch[i] << " ";
			}
			cout << endl;
		}
		else {
			for (int i = s; i < n; i++) {
				ch[l] = i;
				dfs(i + 1, l + 1);
			}
		}
	}
	int main() {
		cin >> n >> r;
		dfs(0, 0);
		return 0;
	}
}