#include <bits/stdc++.h>

using namespace std;

namespace _1620 {
	// cout << endl; 이거 조심하자..
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		int n, m;
		int idx = 1;

		cin >> n >> m;
		map<string, int> m1;
		vector<string> m2(n + 1);

		string name;
		for (int i = 0; i < n; i++) {
			cin >> name;
			m2[idx] = name;
			m1[name] = idx++;
		}
		for (int i = 0; i < m; i++) {
			cin >> name;
			if (name[0] >= 'A' && name[0] <= 'Z') {
				cout << m1[name] << "\n";
			}
			else {
				cout << m2[stoi(name)] << "\n";
			}
		}
		return 0;
	}
}
