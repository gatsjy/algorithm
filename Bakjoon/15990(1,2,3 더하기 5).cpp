#include <bits/stdc++.h>

using namespace std;

// 다음 블로그에서 도움을 받음
// https://jdselectron.tistory.com/71
int t;
long long dp[100001][4];
int mod = 1000000009;
int main() {
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	// 끝이 각각 1,2,3으로 끝날때를 계산해라
	// 끝이 1으로 끝나는데 전번째 1에서 dp를 진행할때는 2와 3만 체크할 수 있다.
	// 각각 1,2,3 차이 나는 거에서 계산하는 이유는 dp를 쌓아 올리기 위해서 이다.
	// dp[i][n] 마지막에 오는 수가 n일때 i를 만드는 개수
	// 마지막에 오는 수가 n이라는 뜻은 그 값을 더한다는 다른 말임!!!
	for (int i = 4; i <= 100000; i++) {
		// 1차이 나는 것중에서 계산하기
		if (i >= 1) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		}
		// 2차이 나는 것중에서 계산하기
		if (i >= 2) {
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		}
		// 3차이 나는 것중에서 계산하기
		if (i >= 3) {
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
		}
	}
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << "\n";
	}

	return 0;
}