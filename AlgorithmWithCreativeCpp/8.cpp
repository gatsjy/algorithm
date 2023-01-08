#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 

string s;
string isStack(string s) {
	stack<char> st;
	bool res = false;
	for (int i = 0; i < s.size(); i++) {
		if (!st.size()) // 스택이 비어있다면?
		{
			if (s[i] == ')') return "NO";
			else {
				st.push('(');
			}
		}
		else { // 스택이 비어있지 않다면?
			if (s[i] == '(') {
				st.push('(');
			}
			else // s[i] == ')'
			{
				if (st.top() == '(') {
					st.pop();
				}
				else { // st.top() == ')'
					st.push(')');
				}
			}
		}
	}

	if (!st.size()) {
		return "YES";
	}
	else {
		return "NO";
	}
}
int main() {
	cin >> s;
	cout << isStack(s);
	return 0;
}