#include <bits/stdc++.h>
using namespace std;
int n, m;

int ch[20];
vector<pair<int, int>> pizza;
vector<pair<int, int>> home;
int dfs(int s, int l, int homeidx) {
	if (l == m) {
		//for (int i = 0; i < m; i++) {
		//	cout << ch[i] << " ";
		//}
		//cout << endl;
		pair<int, int> tmp = home[homeidx];
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += abs(tmp.first - pizza[ch[i]].first) + abs(tmp.second - pizza[ch[i]].second);
		}
		return sum;
	}
	else {
		for (int i = s; i < pizza.size(); i++) {
			ch[l] = i;
			dfs(i + 1, l + 1, homeidx);
		}
	}
}
int main() {
	cin >> n >> m;
	vector<vector<int>> m = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] == 1) {
				home.push_back({ i + 1,j + 1 });
			}else if (m[i][j] == 2) {
				pizza.push_back({ i + 1,j + 1 });
			}
		}
	}

	int res = 2147000000;
	for (int i = 0; i < home.size(); i++) {
		res = min(res, dfs(0, 0, i));
	}

	cout << res;
	 
	return 0;
}