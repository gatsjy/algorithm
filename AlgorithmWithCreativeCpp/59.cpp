#include <bits/stdc++.h>

using namespace std;

namespace _59 {
	int n, ch[11];
	void DFS(int L) {
		int i;
		if (L == n + 1) {
			for (i = 1; i <= n; i++) {
				if (ch[i] == 1) {
					cout << i << " ";
				}
			}
			cout << endl;
			return;
		}
		else {
			ch[L] = 1;
			DFS(L + 1);
			ch[L] = 0;
			DFS(L + 1);
		}
	}

	int main() {
		cin >> n;
		DFS(1);
		return 0;
	}
}
