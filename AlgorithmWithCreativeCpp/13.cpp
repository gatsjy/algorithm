#include <bits/stdc++.h>

using namespace std;
namespace _13 {
	int main() {
		string s;
		cin >> s;
		map<char, int> m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]] += 1;
		}

		int max = -1;
		char maxKey = '0';

		map<char, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++) {
			if (max <= m[iter->first]) {
				max = m[iter->first];
				maxKey = iter->first;
			}
		}
		cout << maxKey;
		return 0;
	}
}