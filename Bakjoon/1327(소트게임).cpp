#include <bits/stdc++.h>

using namespace std;
namespace _1327 {
	int n, k;
	map<string, int> ch;
	queue<pair<string, int>> q;
	string s = "";
	string target = "";
	int main() {

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			s += c;
		}

		// target ¸¸µé±â
		target = s;
		sort(target.begin(), target.end());

		q.push(make_pair(s, 0));

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			if (cur.first == target) {
				cout << ch[target];
				return 0;
			}

			for (int i = 0; i <= n - k; i++) {
				string rtmp = cur.first.substr(i, k);
				reverse(rtmp.begin(), rtmp.end());
				string ns = cur.first.substr(0, i) + rtmp + cur.first.substr(i + k);
				if (ch[ns] != 0) continue;
				ch[ns] = ch[cur.first] + 1;
				q.push(make_pair(ns, cur.second + 1));
			}
		}

		if (ch[target] == 0) {
			cout << -1;
		}
		else {
			cout << ch[target];
		}

		return 0;
	}
}