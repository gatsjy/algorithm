#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
int aa, bb, cc, dd; // µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À
vector<ll> a;
vector<ll> v;
ll  max_res = -2147000000;
ll min_res = 2147000000;
void dfs() {
	if (v.size() == n-1) {
		int taa = 0, tbb = 0, tcc = 0, tdd = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) taa++;
			if (v[i] == 1) tbb++;
			if (v[i] == 2) tcc++;
			if (v[i] == 3) tdd++;
		}
		int tsum = 0;
		if (taa <= aa && tbb <= bb && tcc <= cc && tdd <= dd) {
			tsum = a[0];
			for (int i = 1; i < a.size(); i++) {
				if (v[i - 1] == 0) {
					tsum += a[i];
				}
				else if (v[i - 1] == 1) {
					tsum -= a[i];
				}
				else if (v[i - 1] == 2) {
					tsum *= a[i];
				}
				else if (v[i - 1] == 3) {
					tsum /= a[i];
				}
			}
		}
		if (tsum > max_res) max_res = tsum;
		if (tsum < min_res) min_res = tsum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}
}
int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> aa >> bb >> cc >> dd;

	dfs();

	cout << max_res << "\n";
	cout << min_res << "\n";
	return 0;
}