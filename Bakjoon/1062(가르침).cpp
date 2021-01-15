#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace _1062 {
	int ch[26];
	vector<string> s;
	int n, k;
	vector<int> a;
	int res = -1;
	bool isKnowWard(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (!(ch[s[i] - 'a'] == 1 || ch[s[i] - 'a'] == -1)) {
				return false;
			}
		}
		return true;
	}
	void dfs(int idx) {
		if (a.size() == k - 5) {
			//for (int i = 0; i < a.size(); i++) {
			//	cout << a[i] << " ";
			//}
			//cout << "\n";
			int cnt = 0;
			for (int i = 0; i < s.size(); i++) {
				if (isKnowWard(s[i])) cnt++;
			}
			res = max(res, cnt);
		}
		else {
			for (int i = idx; i < 26; i++) {
				if (ch[i] == 0) {
					a.push_back(i);
					ch[i] = 1;
					dfs(i + 1);
					a.pop_back();
					ch[i] = 0;
				}
			}
		}
	}
	int main() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		// antic 매핑
		ch['a' - 'a'] = -1;
		ch['n' - 'a'] = -1;
		ch['t' - 'a'] = -1;
		ch['i' - 'a'] = -1;
		ch['c' - 'a'] = -1;

		cin >> n >> k;
		if (k < 5) {
			cout << 0;
			return 0;
		}
		else {
			s.resize(n);
			for (int i = 0; i < n; i++) {
				cin >> s[i];
			}

			// k-5 개 순열 구하기
			dfs(0);
		}

		cout << res;
		return 0;
	}
}