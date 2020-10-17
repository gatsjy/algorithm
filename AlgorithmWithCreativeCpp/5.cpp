#include <bits/stdc++.h>

using namespace std;
namespace _10{
	void main() {
		// 주민등록증을 기준으로 나이를 구하라.
		string s;
		cin >> s;
		char sex = 'M';
		int age = 0;
		// 1. 1900년대 남자
		if (s[7] == '1') {
			sex = 'M';
			age = 100 - stoi(s.substr(0, 2)) + 20;
		}
		// 2. 1900년대 여자
		else if (s[7] == '2') {
			sex = 'W';
			age = 100 - stoi(s.substr(0, 2)) + 20;
		}
		// 3. 2000년대 남자
		else if (s[7] == '3') {
			sex = 'M';
			age = 20 - stoi(s.substr(0, 2));
		}
		// 4. 2000년대 여자
		else if (s[7] == '4') {
			sex = 'W';
			age = 20 - stoi(s.substr(0, 2));
		}
		cout << age << " " << sex;
	}
}