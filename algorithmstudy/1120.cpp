#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

namespace BOJ_1120 {
	int compare(string root, string target) {
		int cnt = 0;
		for (int i = 0; i < root.size(); i++) {
			if (root[i] != target[i]) cnt++;
		}
		return cnt;
	}

	int main() {
		string s1, s2;

		cin >> s1 >> s2;


		string fronts2 = "";
		if (s2.size() > s1.size()) {
			fronts2 = s2.substr(0, s1.size());
		}
		else {
			fronts2 = s2;
		}

		string ends2 = "";
		if (s2.size() > s1.size()) {
			ends2 = s2.substr(s2.size() - s1.size());
		}
		else {
			ends2 = s2;
		}

		cout << min(compare(s1, fronts2), compare(s1, ends2));

		return 0;
	}
}
