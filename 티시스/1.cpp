#include <iostream>

using namespace std;
int n;
int board[21][21];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	// 2021-01-21, 한주안, 최초 작성
	// ** 배열을 사용하지 않고 푸는 방법도 있겠지만,
	// ** 누구나 한눈에 알아볼 수 있는 코드의 유지보수성이 메모리의 지속적 사용보단 낫다고 판단

	// 입력값 유효성 체크 (20이하의 자연수)
	if (n <= 20) {
		// 1. 배열에 하나하나 넣어줄 cnt 변수 선언
		int cnt = 1;

		// 2. 배열에 할당
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[j][i] = cnt++;
			}
		}

		// 2. 출력해주는 부분
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}