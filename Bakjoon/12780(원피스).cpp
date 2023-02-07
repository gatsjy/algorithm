#include <bits/stdc++.h>

using namespace std;

string h, n;
int c;
int main() {
	cin >> h >> n;

	for (int i = 0; i <= h.size() - n.size(); i++) {
		if (h.substr(i, n.size()) == n) {
			c++;
		}
	}

	cout << c;
	return 0;
}