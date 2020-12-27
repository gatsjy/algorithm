#include<bits/stdc++.h>

using namespace std;

namespace _2512 {
	vector<long long> v;
	long long budget;
	int n;
	long long res = -1;
	int main() {
		cin >> n;
		v.resize(n);
		long long lt = 1;
		long long rt = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			rt = max(rt, v[i]);

		}
		cin >> budget;

		while (lt <= rt) {
			long long mid = (lt + rt) / 2;
			long long tbudget = 0;
			for (int i = 0; i < n; i++) {
				tbudget += min(v[i], mid);
			}
			if (tbudget > budget) // 임시값이 원래값보다 크면 작은 범위 탐색
			{
				rt = mid - 1;
			}
			else {
				lt = mid + 1;
				// 최적의 값을 바라보면서 올라가야 하니까...
				// 임시 budget이 높으면 그것이 최적의 답안이 될 수 없다.
				res = max(res, mid);
			}
		}
		cout << res;
		return 0;
	}
}