#include <bits/stdc++.h>

using namespace std;

int n, m,k;

// 이렇게 접근해서는 안됨 반례가 엄청생김..

int board[12][12];
vector<int> a;
vector<int> b;
int res = -1;
vector<int> v;
int ch[100];
void dfs(int idx, int level, vector<int> &arr) {
	if (v.size() == k) {
		int tmp = 0;
		for (int i = 0; i < k; i++) {
			cout << v[i] << " ";
			tmp += v[i];
		}
		cout << "\n";
		if (tmp > res) res = tmp;
	}
	else {
		for (int i = idx; i < arr.size(); i++) {
			if (ch[i] == 0) {
				v.push_back(arr[i]);
				ch[i] = 1;
				dfs(idx + 1, level + 1, arr);
				v.pop_back();
				ch[i] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				a.push_back(board[i][j]);
			}
			else if (i % 2 == 0 && j % 2 == 1) {
				b.push_back(board[i][j]);
			}
			else if (i % 2 == 1 && j % 2 == 0) {
				b.push_back(board[i][j]);
			}
			else {
				a.push_back(board[i][j]);
			}
		}
	}

	// a배열 돌리기
	dfs(0,0,a);

	// b배열 돌리기
	dfs(0,0,b);

	cout << res;
	return 0;
}