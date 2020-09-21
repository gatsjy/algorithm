#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dp[501][501] = { 0, };

namespace 정수삼각형 {
	int solution(vector<vector<int>> triangle) {
		// 1. 위치 값 확인하는 코드
		/*for (int i = 0; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				dp[i][j] = triangle[i][j];
			}
		}*/
		// 해당 값을 계산한다.
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				if (j == 0) {
					dp[i][j] = triangle[i][j] + dp[i - 1][j];
				}
				else if (j != 0) {
					dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
				}
			}
		}
		int answer = -1;
		for (int i = 0; i < triangle.size(); i++) {
			answer = max(answer, dp[triangle.size() - 1][i]);
		}
		return answer;
	}

	int main() {
		vector<vector<int>> triangle = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };
		//7
		//38
		//810
		//2744
		//45265

		//7
		//10 15
		//18 16 15
		//20 25 20 19
		//24 30 27 26 24
		solution(triangle);
		return 0;
	}
}

