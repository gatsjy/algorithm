#include <bits/stdc++.h>

using namespace std;

namespace _8 {
	int main() {
		stack<char> st;

		string s;
		cin >> s;
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push('(');
			}
			else if (s[i] == ')') {
				if (st.empty()) {
					flag = false;
					break;
				}
				else if (!st.empty()) {
					st.pop();
				}
			}
		}
		if (flag) {
			if (!st.empty()) {
				flag = false;
			}
		}
		if (flag) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
}