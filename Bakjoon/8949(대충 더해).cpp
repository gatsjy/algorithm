#include <bits/stdc++.h>

using namespace std;

namespace _8949 {
	string s1, s2;
	stack<int> st;
	int main() {
		cin >> s1 >> s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());

		int idx = 0;
		while (idx < s1.size() && idx < s2.size()) {
			st.push((s1[idx] - '0') + (s2[idx] - '0'));
			idx++;
		}
		while (idx < s1.size()) {
			st.push(s1[idx] - '0');
			idx++;
		}
		while (idx < s2.size()) {
			st.push(s2[idx] - '0');
			idx++;
		}

		string res = "";
		while (!st.empty()) {
			int tmp = st.top();
			res += to_string(tmp);
			st.pop();
		}
		cout << res;
		return 0;
	}
}