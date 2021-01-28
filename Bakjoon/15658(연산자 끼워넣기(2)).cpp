#include <bits/stdc++.h>

using namespace std;

namespace _15658 {
	typedef long long ll;
	int n;
	int aa, bb, cc, dd; // µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À
	vector<ll> a(12);
	vector<ll> v(5);
	ll max_res = -2147000000;
	ll min_res = 2147000000;

	void solution(int sum, int idx, int aa, int bb, int cc, int dd) {
		if (idx == n) {
			if (sum > max_res) max_res = sum;
			if (sum < min_res) min_res = sum;
			return;
		}
		if (aa > 0) {
			solution(sum + a[idx], idx + 1, aa - 1, bb, cc, dd);
		}
		if (bb > 0) {
			solution(sum - a[idx], idx + 1, aa, bb - 1, cc, dd);
		}
		if (cc > 0) {
			solution(sum * a[idx], idx + 1, aa, bb, cc - 1, dd);
		}
		if (dd > 0) {
			solution(sum / a[idx], idx + 1, aa, bb, cc, dd - 1);
		}
	}

	int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i <= 4; i++) {
			cin >> v[i];
		}

		solution(a[0], 1, v[1], v[2], v[3], v[4]);
		cout << max_res << "\n";
		cout << min_res;
		return 0;
	}
}