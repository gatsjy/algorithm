#include <bits/stdc++.h>

namespace _1940 {
	using namespace std;
	int n, m;
	bool ch[15001];
	vector<int> v;
	vector<int> a;
	int cnt = 0;
	void dfs(int idx) {
		if (v.size() == 2) {
			int sum = 0;
			for (int i = 0; i < v.size(); i++) {
				//cout << v[i] << " ";
				sum += v[i];
			}
			if (sum == m) cnt++;
		}
		else {
			for (int i = idx; i < n; i++) {
				if (ch[i] == 0) {
					ch[i] == 1;
					v.push_back(a[i]);
					dfs(i + 1);
					ch[i] == 0;
					v.pop_back();
				}
			}
		}
	}
	int main() {
		cin >> n >> m;
		int input;
		for (int i = 0; i < n; i++) {
			cin >> input;
			a.push_back(input);
		}
		dfs(0);
		cout << cnt;
		return 0;
	}
}