#include <bits/stdc++.h>

using namespace std;

string s, res;
int main() {

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) {
			res += tolower(s[i]);
		}
		else {
			res += toupper(s[i]);
		}
	}
	
	cout << res;

	return 0;
}