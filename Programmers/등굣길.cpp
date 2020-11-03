#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

namespace _등굣길 {
	using namespace std;
	int dp[101][101];
	int ch[101][101];

	// 1. 내가 뭔가 x,y에 대한 위치를 변경해야한다...
	// 내가 지금 잊고 있는게 무엇일까??

	int solution(int m, int n, vector<vector<int>> puddles) {
		for (int i = 0; i < puddles.size(); i++) {
			dp[puddles[i][1]][puddles[i][0]] = -1;
		}
		dp[1][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (dp[i][j] == -1) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
				}
			}
		}
		return dp[n][m];
	}

	int main() {
		int m = 4;
		int n = 3;
		vector<vector<int>> puddles = { {2,2} };
		solution(m, n, puddles);
		return 0;
	}
}