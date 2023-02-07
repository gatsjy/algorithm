#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
	cin >> s;
	bool flag = false;
	for (int i = 1; i < s.size(); i++) {
		if (flag) break;
		int front = 1;
		// 앞자리
		for (int j = 0; j < s.substr(0, i).size(); j++) {
			front *= s.substr(0, i)[j] - '0';
		}
		int back = 1;
		// 뒷자리
		for (int k = 0; k < s.substr(i, s.size()).size(); k++) {
			back *= s.substr(i, s.size())[k] - '0';
		}
		if (front == back) flag = true;
	}
	
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}