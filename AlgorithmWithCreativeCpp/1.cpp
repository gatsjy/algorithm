#include<bits/stdc++.h>

using namespace std;
int n, m, sum;
int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (!(i % m)) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}