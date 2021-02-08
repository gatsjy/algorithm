#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

namespace _문자열재정렬 {
	string s;

	int main() {
		cin >> s;

		vector<char> c;
		int res = 0;

		for (int i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) {
				c.push_back(s[i]);
			}
			else {
				res += s[i] - '0';
			}
		}
		sort(c.begin(), c.end());
		for (int i = 0; i < c.size(); i++) {
			cout << c[i];
		}
		cout << res;
		return 0;
	}
}