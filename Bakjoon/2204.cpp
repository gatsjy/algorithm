#include <bits/stdc++.h>

using namespace std;
namespace _2204 {
	struct name {
		string s;
		name(string ss) {
			s = ss;
		}
		bool operator <(const name& b)const {
			string ta = s;
			string tb = b.s;
			for (int i = 0; i < ta.size(); i++) {
				ta[i] = tolower(ta[i]);
			}
			for (int i = 0; i < tb.size(); i++) {
				tb[i] = tolower(tb[i]);
			}
			return ta > tb;
		}
	};

	int main() {
		int n;
		string s;
		while (1) {
			cin >> n;
			if (n == 0) break;
			priority_queue<name> pq;
			for (int i = 0; i < n; i++) {
				cin >> s;
				pq.push(name(s));
			}
			cout << pq.top().s << "\n";
		}
		return 0;
	}
}