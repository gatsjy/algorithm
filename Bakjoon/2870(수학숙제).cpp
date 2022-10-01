#include <bits/stdc++.h>

using namespace std;

int n;
string s, input;
vector<string> res;
void parseInt() {
	if (input.size()) {
		while (1) {
			if (input.size() && input.front() == '0') input.erase(input.begin());
			else break;
		}
		if (input.size() == 0) input = "0";
		res.push_back(input);
		input = "";
	}
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size(); // true면 뒤에 온다.
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		input == "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 58) input += s[j];
			else {
				parseInt();
			}
		}
		parseInt();
	}

	sort(res.begin(), res.end(), cmp);

	for (auto s : res) {
		cout << s << "\n";
	}
	return 0;

}