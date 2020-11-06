#include <bits/stdc++.h>
using namespace std;

namespace _네트워크_선_자르기_Top_Down {
	int dp[50] = { 0, };
	int dfs(int v) {
		if (dp[v] > 0) return dp[v];
		if (v == 1 || v == 2)return v;
		return dp[v] = dfs(v - 1) + dfs(v - 2);
	}

	int main() {
		dp[1] = 1;
		dp[2] = 2;
		int n;
		cin >> n;
		cout << dfs(n);
		return 0;
	}
}
