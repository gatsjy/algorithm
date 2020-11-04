#include <bits/stdc++.h>

using namespace std;

namespace _1235 {
	int main() {
		int n;
		cin >> n;
		string s;
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> s;
			v[i] = s;
		}

		for (int i = 1; i <= v[0].size(); i++) {
			map<string, int> m; // 중복 체크용 map
			for (int j = 0; j < v.size(); j++) {
				m[v[j].substr(v[j].size() - i)]++;
				if (m[v[j].substr(v[j].size() - i)] > 1) {
					break;
				}
				if (j == v.size() - 1) {
					cout << i;
					return 0;
				}
			}
		}
		return 0;
	}
}