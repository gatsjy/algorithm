#include<bits/stdc++.h>
using namespace std;

string s;
string sex;
bool century;
int age;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;

	// 올해느 2019년
	if (s[7] == '1') {
		sex = 'M';
	}
	else if (s[7] == '2') {
		sex = 'W';
	}
	else if (s[7] == '3') {
		sex = 'M';
		century = true;
	}
	else if (s[7] == '4') {
		sex = 'W';
		century = true;
	}
	
	string sage = s.substr(0, 2);
	if (century) {
		age = 20 - atoi(sage.c_str());
	}
	else {
		age = 120 - atoi(sage.c_str());
	}

	cout << age<< " " << sex;

	return 0;
}