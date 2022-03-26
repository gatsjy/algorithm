#include <bits/stdc++.h>

using namespace std;

vector <long> res;

int n;
string s;

void parseInt(string s) {
	string input;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			input += s[i];
		}
		else {
			if (input != "") {
				res.push_back(stol(input));
			}
			input = "";
		}
	}
	if (input != "") {
		res.push_back(stol(input));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		parseInt(s);
	}

	sort(res.begin(), res.end());

	for (long _res : res) {
		cout << _res << "\n";
	}
	return 0;
}