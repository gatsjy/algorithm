#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	string s;
	for(int i = 0 ; i < n ; i++){
		stack<string> st;
		getline(cin, s);
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				st.push(tmp);
				tmp = "";
			}
			else {
				tmp += s[i];
			}
		}
		st.push(tmp);
		cout << "Case #" << i + 1 << ": ";
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		if (i != n - 1) {
			cout << "\n";
		}
	}
	return 0;
}