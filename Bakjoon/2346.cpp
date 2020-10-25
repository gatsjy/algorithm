#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		v.push_back(make_pair(i,input));
	}
	vector<int> ans;
	while (v.size() > 1) {
		auto cur = v[0];
		v.erase(v.begin());
		int nextval = cur.second;
		if (nextval > 0) {
			for (int i = 0; i < nextval-1; i++) {
				v.push_back(v[0]);
				v.erase(v.begin());
			}
		}
		else {
			for (int i = 0; i < -1 * nextval; i++) {
				v.insert(v.begin(), v.back());
				v.pop_back();
			}
		}
		ans.push_back(v.begin()->first);
	}

	cout << "1" << " ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}