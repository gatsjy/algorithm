#include <bits/stdc++.h>

using namespace std;

namespace _1360 {
	vector<pair<string, int>> words;
	int n, b;
	string s, a;

	string calString(int sec) {
		for (int i = words.size() - 1; i >= 0; i--) {
			if (words[i].second < sec) {
				return words[i].first;
			}
		}
		return "";
	}
	int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> a >> b;
			if (s[0] == 't') {
				string cur = "";
				if (words.size()) {
					cur = words.back().first + a;
				}
				else {
					cur = a;
				}
				words.push_back({ cur, b });
			}
			else if (s[0] == 'u') {
				words.push_back({ calString(b - atoi(a.c_str())), b });
			}
		}
		cout << words.back().first;
		return 0;
	}
}
