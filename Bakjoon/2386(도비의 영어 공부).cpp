#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
char s1;
string s2;
int main() {
	while (1) {
		cin >> s1;
		if (s1 == '#') break;
		getline(cin, s2);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		int cnt = 0;
		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] == s1) {
				cnt++;
			}
		}
		cout << s1 << " " << cnt << "\n";
	}
	return 0;
}