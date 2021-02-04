#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> crain;
vector<int> box;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	crain.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}
	cin >> m;
	box.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}

	sort(crain.begin(), crain.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());
	int cnt = 0;
	if (crain[0] < box[0]) {
		cout << -1;
		return 0;
	}
	else {
		while (box.size()) {
			int idx = 0;
			for (int i = 0; i < box.size(); i++) {
				if (idx == crain.size()) {
					break;
				}
				if (box[i] <= crain[idx]) {
					idx++;
					box.erase(box.begin() + i);
					i--;
				}
			}
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}