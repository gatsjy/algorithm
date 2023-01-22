#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
string s;
int n;

int main() {
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "pop") {
			if (st.size() == 0) {
				cout << "-1" << "\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (s == "size") {
			cout << st.size() << "\n";
		}
		else if (s == "empty") {
			if (st.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (s == "top") {
			if (st.size() == 0) {
				cout << "-1" << "\n";
			}
			else {
				cout << st.top() << "\n";
			}
		}
		else if (s == "push") {
			string tmp;
			cin >> tmp;
			st.push(stoi(tmp));
		}
	}
	return 0;
}