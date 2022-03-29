#include<bits/stdc++.h>

using namespace std;
int n, m, b[104][104], cnt;
string _map[104];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> _map[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (_map[i][j] == 'c') b[i][j] = 0;
			else {
				b[i][j] = -1;
			}
		}
	}

	for (int i = 1; i < m; i++) {
		cnt++;
		if (_map[0][i - 1] == 'c') {
			_map[0][i] = 'c';
			_map[0][i - 1] = '.';
		}
		else {
			b[0][i] = cnt;
		}
	}

	return 0;
}