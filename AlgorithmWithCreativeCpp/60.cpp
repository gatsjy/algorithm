#include <bits/stdc++.h>

using namespace std;
namespace _60 {
	int i, n, a[11], total;
	bool flag = false;
	void DFS(int L, int sum) {
		if (flag) return;
		if (L == n + 1) {
			if (sum == (total - sum)) {
				flag = true;
			}
		}
		else {
			DFS(L + 1, sum);
			DFS(L + 1, sum + a[L]);
		}
	}
	int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i + 1];
			total += a[i + 1];
		}
		DFS(1, 0);

		if (flag) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		return 0;
	}
}
