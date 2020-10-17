#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[60] = { 0 };
	int b[60] = { 0 };

	string s1, s2;

	cin >> s1 >> s2;
	// 아스키코드가 중간에 7개가 비어서 이런식으로 처리해야 한다.
	for (int i = 0; i < s1.size(); i++) {
		a[s1[i] - 'A']++;
	}
	for (int i = 0; i < s2.size(); i++) {
		b[s2[i] - 'A']++;
	}

	int flag = true;
	for (int i = 0; i < 60; i++) {
		if (a[i] != b[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}