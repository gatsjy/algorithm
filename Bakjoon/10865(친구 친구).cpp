#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[100001];
int c, d;
int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		cin >> c >> d;
		a[c]++;
		a[d]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << "\n";
	}
	return 0;
}