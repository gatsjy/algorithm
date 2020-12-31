#include <bits/stdc++.h>

using namespace std;

int n;
int board[11][11];
bool ch[11];
vector<int> v;
int res = 2147000000;
void dfs(int idx) {
	if (v.size() == n) {
		//for (int i = 0; i < 4; i++) {
		//	cout << v[i] << " ";
		//}
		//cout << "\n";
		int sum = 0;
		for (int i = 0; i < v.size()-1; i++) {
			if (board[v[i]][v[i + 1]] == 0) return;
			sum += board[v[i]][v[i + 1]];
		}
		if (board[v[v.size() - 1]][v[0]] == 0) return;
		sum += board[v[v.size() - 1]][v[0]];
		res = min(res, sum);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (ch[i] == 0) {
				v.push_back(i);
				ch[i] = 1;
				dfs(i + 1);
				v.pop_back();
				ch[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0);

	cout << res;

	return 0;
}