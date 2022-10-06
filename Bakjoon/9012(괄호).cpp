#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string isStc(string s) {
	
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (st.size() == 0) {
			if (s[i] == ')') return "NO";
			else st.push(s[i]);
		}
		else {
			if (s[i] == '(') {
				st.push('(');
			}
			else { // s[i] == ')'
				if (st.empty()) return "NO";
				else st.pop();
			}
		}
	}
	if (!st.empty()) return "NO";
	return "YES";
}
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
		cout << isStc(s) << "\n";
	}

	return 0;
}