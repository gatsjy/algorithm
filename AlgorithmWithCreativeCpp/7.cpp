#include <bits/stdc++.h>

using namespace std;

namespace _6 {
	void main() {
		string s, tmp;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') tmp += s[i];
		}
		for (int i = 0; i < tmp.size(); i++) {
			tmp[i] = tolower(tmp[i]);
		}
		cout << tmp;
	}
}
