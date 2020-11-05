#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push('(');
		}
		else if (s[i] == ')') {
			st.pop();
			sum += st.size();
		}
	}
	cout << sum;
	return 0;
}