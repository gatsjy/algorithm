#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 

string s;
string isStack(string s) {
	stack<char> st;
	bool res = false;
	for (int i = 0; i < s.size(); i++) {
		if (!st.size()) // ������ ����ִٸ�?
		{
			if (s[i] == ')') return "NO";
			else {
				st.push('(');
			}
		}
		else { // ������ ������� �ʴٸ�?
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