#include <bits/stdc++.h>

using namespace std;

namespace _6321 {
	int main() {

		int n;
		cin >> n;
		string s;
		int cnt = 1;
		while (n--) {
			cin >> s;
			cout << "String #" << cnt++ << endl;
			string tmp = "";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == 'Z') {
					tmp += 'A';
				}
				else {
					tmp += s[i] + 1;
				}
			}
			cout << tmp << endl;
			if (cnt != 0) {
				cout << endl;
			}
		}
		return 0;
	}
}
