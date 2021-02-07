#include <bits/stdc++.h>

using namespace std;

namespace _9465 {
	int c, n;
	int stk[2][100001];
	int dp[2][100001];
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		// 1. 테이블 정의 dp[i][j]= (i,j)에서 선택할 수 있는 최대 값
		// 2. 점화식 구하기
		// 3. 기본값 세팅
		cin >> c;
		while (c--) {
			memset(stk, 0, sizeof(stk));
			memset(dp, 0, sizeof(dp));
			cin >> n;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < n; j++) {
					cin >> stk[i][j];
				}
			}
			// 기본값 세팅한다
			dp[0][0] = stk[0][0];
			dp[1][0] = stk[1][0];
			dp[0][1] = stk[0][1] + stk[1][0];
			dp[1][1] = stk[1][1] + stk[0][0];
			for (int i = 2; i <= n; i++) {
				dp[0][i] = stk[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
				dp[1][i] = stk[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
			}
			cout << max(dp[0][n], dp[1][n]) << "\n";
		}
		return 0;
	}
}
