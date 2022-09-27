#include <bits/stdc++.h>

using namespace std;

int n;
int a[81][81];

string go(int y, int x, int cnt) {
	int nct = cnt / 2;
	if (cnt == 1) return to_string(a[y][x]);
	string go1 = go(y, x, nct);
	string go2 = go(y, x + nct, nct);
	string go3 = go(y + nct, x, nct);
	string go4 = go(y + nct, x + nct, nct);
	if (go1 == go2 && go2 == go3 && go3 == go4) return go1;
	return "(" + go1 + go2 + go3 + go4 + ")";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	// 4번의 쿼드트리 로직을 발생시킨다.
	cout << go(0, 0, n);
	return 0;
}