#include <bits/stdc++.h>

using namespace std;

string s;
bool isLucky(string s) {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> s;
	int cnt = 0;
	sort(s.begin(), s.end()); // 다시 처음부터 시작
	do {
		if (isLucky(s)) cnt++;
	} while (next_permutation(s.begin(), s.end()));

	cout << cnt;
	return 0;
}