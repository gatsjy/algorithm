#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int k[15001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (k[i] + k[j] == m) cnt++;
		}
	}
	cout << cnt;

	return 0;
}