#include <bits/stdc++.h>

using namespace std;
namespace _10872 {
	int dp[100001];

	int factorial(int v) {
		if (dp[v] > 0) return dp[v];
		if (v == 0 || v == 1) return 1;
		else return dp[v] = v * factorial(v - 1);
	}


	int main() {

		int n;
		cin >> n;
		cout << factorial(n);
		return 0;
	}
}
