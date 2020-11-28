#include <bits/stdc++.h>

using namespace std;

namespace _8892 {
	int T, N;
	vector<string> strs;
	bool isPelindrom(string s) {
		for (int i = 0; i <= s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i]) {
				return false;
			}
		}
		return true;
	}

	void solve() {
		cin >> N;
		strs.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> strs[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				string tmp = strs[i] + strs[j];
				if (isPelindrom(tmp)) {
					cout << tmp << "\n";
					return;
				}
			}
		}
		cout << "0" << "\n";
	}

	int main() {
		cin >> T;
		while (T--) {
			solve();
		}
		return 0;
	}
}
