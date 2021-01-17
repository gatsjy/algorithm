#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<ll> v;
vector<ll> a;
vector<bool> ch;
ll n, l, r, x;
int cnt = 0;
void dfs(int idx, int size) {
	if (size == a.size()) {
		int sum = 0;
		ll max_value = -1;
		ll min_value = 2147000000;
		for (int i = 0; i < a.size(); i++) {
			sum += a[i];
			if (max_value < a[i]) max_value = a[i];
			if (min_value > a[i]) min_value = a[i];
		}
		if (sum >= l && sum <= r && max_value - min_value >= x) {
			cnt++;
		}
		//for (int i = 0; i < size; i++) {
		//	cout << a[i] << " ";
		//}
		//cout << "\n";
	}
	else {
		for (int i = idx; i < n; i++) {
			if (ch[i] == 0) {
				a.push_back(v[i]);
				ch[i] = 1;
				dfs(i + 1, size);
				a.pop_back();
				ch[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r >> x;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		ch.resize(n);
		dfs(0, i);
	}
	cout << cnt;
	return 0;
}