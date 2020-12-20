#include <bits/stdc++.h>

using namespace std;

namespace _18258 {
	int n, input;
	string s;
	queue<int> q;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		while (n--) {
			cin >> s;
			if (s == "push") {
				cin >> input;
				q.push(input);
			}
			else if (s == "front") {
				if (q.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << q.front() << "\n";
				}
			}
			else if (s == "back")
			{
				if (q.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << q.back() << "\n";
				}
			}
			else if (s == "size") {
				cout << q.size() << "\n";
			}
			else if (s == "empty")
			{
				cout << q.empty() << "\n";
			}
			else // s=="pop"
			{
				if (q.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << q.front() << "\n";
					q.pop();
				}
			}
		}
		return 0;
	}
}