#include <bits/stdc++.h>

using namespace std;

namespace _1406 {
	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		string s;
		cin >> s;
		list<char> L;
		for (char c : s) L.push_back(c);
		auto cursor = L.end();
		int q;
		cin >> q;
		while (q--) {
			char op;
			cin >> op;
			if (op == 'L') {
				if (cursor != L.begin()) cursor--;
			}
			else if (op == 'D') {
				if (cursor != L.end()) cursor++;
			}
			else if (op == 'P') {
				char value;
				cin >> value;
				L.insert(cursor, value);
			}
			else { // 'B'
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
		}
		for (auto c : L) cout << c;
		return 0;
	}
}
