#include <bits/stdc++.h>

using namespace std;

namespace _9086 {
	int main() {
		int n;
		cin >> n;
		string s;
		while (n--) {
			cin >> s;
			cout << s[0] << s[s.size() - 1] << endl;
		}
		return 0;
	}
}