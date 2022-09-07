#include <bits/stdc++.h>

using namespace std;

vector<string> p;
int c[50];
int n;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		c[input[0] - 'a']++;
	}

	string s;
	int cnt = 0;
	for (int i = 0; i < 30; i++) {
		if (c[i] >= 5) {
			s += (i + 'a');
			cnt++;
		}
	}

	if (cnt == 0) {
		cout << "PREDAJA";
	}
	else {
		cout << s;
	}
	return 0;
}