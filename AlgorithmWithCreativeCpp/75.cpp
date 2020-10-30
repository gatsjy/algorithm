#include <bits/stdc++.h>

using namespace std;

namespace _75 {
	struct Data {
		int money;
		int when;
		Data(int a, int b) {
			money = a;
			when = b;
		}
		bool operator<(Data& b) {
			return when > b.when;
		}
	};

	int main() {
		int n;
		cin >> n;
		int a, b, max = -2147000000;
		vector<Data> v;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back(Data(a, b));
			if (max < b) {
				max = b;
			}
		}
		sort(v.begin(), v.end());

		int res = 0;
		priority_queue<int> pq;
		int j = 0;
		for (int i = max; i >= 1; i--) {
			for (; j < n; j++) {
				if (v[j].when < i)break;
				pq.push(v[j].money);
			}
			if (!pq.empty()) {
				res += pq.top();
				pq.pop();
			}
		}
		cout << res;
		return 0;
	}
}
