#include <bits/stdc++.h>

using namespace std;

namespace _11023 {
	int main() {
		string s;
		getline(cin, s);
		string tmp = "";
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				sum += stoi(tmp);
				tmp = "";
			}
			else {
				tmp += s[i];
			}
		}
		sum += stoi(tmp);
		cout << sum;
		return 0;
	}
}
