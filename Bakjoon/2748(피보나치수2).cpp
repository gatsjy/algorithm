#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[101];

int main() {

	a[0] = 0;
	a[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 2] + a[i - 1];
	}

	cout << a[n];
	return 0;
}