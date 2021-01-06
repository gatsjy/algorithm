#include <iostream>

using namespace std;

namespace _15988 {
	long long dp[1000001] = { 0, 1, 2, 4 };

	const long long mod = 1000000009;

	long long DP(int n)
	{
		if (n <= 0)return 0;
		if (dp[n])return dp[n];
		for (int i = 4; i <= 1000000; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
		}
		return dp[n];
	}

	int main()
	{
		long long T;
		long long n;
		cin >> T;

		while (T--)
		{
			cin >> n;
			cout << DP(n) << "\n";
		}
		return 0;
	}
}