#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[10001];

ll mod = 1000000; 
int fibo(int n) {
	if (n == 1 || n == 0) return n;
	return fibo(n - 2) % mod + fibo(n - 1) % mod;
}

int main() {

	a[1] = 1;

	int n;
	cin >> n;

	cout << fibo(n);
	return 0;
}