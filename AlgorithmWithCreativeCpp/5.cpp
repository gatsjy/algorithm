#include <bits/stdc++.h>

using namespace std;
namespace _10{
	void main() {
		// �ֹε������ �������� ���̸� ���϶�.
		string s;
		cin >> s;
		char sex = 'M';
		int age = 0;
		// 1. 1900��� ����
		if (s[7] == '1') {
			sex = 'M';
			age = 100 - stoi(s.substr(0, 2)) + 20;
		}
		// 2. 1900��� ����
		else if (s[7] == '2') {
			sex = 'W';
			age = 100 - stoi(s.substr(0, 2)) + 20;
		}
		// 3. 2000��� ����
		else if (s[7] == '3') {
			sex = 'M';
			age = 20 - stoi(s.substr(0, 2));
		}
		// 4. 2000��� ����
		else if (s[7] == '4') {
			sex = 'W';
			age = 20 - stoi(s.substr(0, 2));
		}
		cout << age << " " << sex;
	}
}