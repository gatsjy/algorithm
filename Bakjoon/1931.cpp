#include <bits/stdc++.h>

using namespace std;

namespace _1931 {
	struct room {
		long start;
		long end;

		room(long a, long b) {
			start = a;
			end = b;
		}

		bool operator<(const room& b) const {
			if (end == b.end) {
				return start < b.start;
			}
			return end < b.end;
		}
	};
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		long n, start, end;

		cin >> n;
		vector<room> a;
		for (int i = 0; i < n; i++) {
			cin >> start >> end;
			a.push_back(room(start, end));
		}

		sort(a.begin(), a.end());

		int cnt = 0;
		int endTime = 0;
		for (int i = 0; i < a.size(); i++) {
			if (endTime <= a[i].start) {
				endTime = a[i].end;
				cnt++;
			}
		}

		cout << cnt;
		return 0;
	}
}