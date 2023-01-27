#include <bits/stdc++.h>

using namespace std;

string s;
int n,m;
int main() {
	cin >> n >> m;

	string tmp = "";
	for (int i = 0; i < n; i++) {
		tmp += to_string(n);
	}

	cout << tmp.substr(0, m);
	return 0;
}