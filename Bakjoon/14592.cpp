#include <bits/stdc++.h>

using namespace std;

namespace _14592 {
	struct test {
		int score;
		int submit;
		int time;
		int idx;
		test(int a, int b, int c, int d) {
			score = a;
			submit = b;
			time = c;
			idx = d;
		}

		bool operator<(test& b) {
			if (score == b.score) {
				if (submit == b.submit) {
					return time < b.time;
				}
				else {
					return submit < b.submit;
				}
			}
			else {
				return score > b.score;
			}
		}
	};
	int main() {
		int n;
		cin >> n;
		vector<test> v;
		int a, b, c;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			v.push_back(test(a, b, c, i));
		}
		sort(v.begin(), v.end());
		cout << v[0].idx;
		return 0;
	}
}
