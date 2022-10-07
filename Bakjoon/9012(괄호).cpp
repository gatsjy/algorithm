#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string isStc(string s) {
	
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (!(s[i] == '(' || s[i] == '[' || s[i] == ')' || s[i] == ']')) continue;
		if (st.size() == 0) {
			if (s[i] == ')') return "no";
			if (s[i] == ']') return "no";

			else st.push(s[i]);
		}
		else {
			if (s[i] == '(') {
				st.push('(');
			}
			else if (s[i] == '[') {
				st.push('[');
			}
			else if (s[i] == ')') {
				if (st.empty()) return "no";
				else if (st.top() != '(') return "no";
				else st.pop();
			}
			else if (s[i] == ']') {
				if (st.empty()) return "no";
				else if (st.top() != '[') return "no";
				else st.pop();
			}
		}
	}
	if (!st.empty()) return "no";
	return "yes";
}
int main() {
	while (1) {
		getline(cin, s);
		if (s == ".") break;
		cout << isStc(s) << "\n";
	}

	return 0;
}