#include <bits/stdc++.h>

using namespace std;

namespace _53 {
	int main() {
		stack<int> st;
		int i, j = 1, n, input;
		cin >> n;
		vector<char> res;
		for (int i = 0; i < n; i++) {
			cin >> input;
			st.push(input);
			res.push_back('P');
			while (1) {
				if (st.empty()) break;
				if (st.top() == j) {
					st.pop();
					res.push_back('O');
					j++;
				}
				else {
					break;
				}
			}
		}
		if (!st.empty()) {
			cout << "impossible";
			return 0;
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
		}
		return 0;
	}
}