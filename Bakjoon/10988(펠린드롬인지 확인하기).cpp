#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string s;
	cin >> s;
	string real = s;
	reverse(s.begin(), s.end());
	if (real == s) cout << 1;
	else cout << 0;

	return 0;
}