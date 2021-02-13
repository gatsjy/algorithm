#include <bits/stdc++.h>

using namespace std;
#define MAX 101
int ch[MAX][MAX];
int n, m, a, b;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ch[a][b] = 1;
	}

	for (int item = 1; item <= n; item++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (ch[i][item] && ch[item][j]) {
					ch[i][j] = 1;
				}
			}
		}
	}

	for (int item = 1; item <= n; item++) {
		int bigger = 0; int smaller = 0;
		for (int i = 1; i <= n; i++) {
			if (item == i) continue;
			if (ch[item][i]) smaller++;
			if (ch[i][item]) bigger++;
		}
		cout << n - bigger - smaller - 1 << "\n";
	}

	return 0;
}