#include <bits/stdc++.h>

using namespace std;

namespace _19 {
	int main() {
		int N;
		cin >> N;

		vector<int> student(N);

		// 1. 학생 배열 만들기
		for (int i = 0; i < N; i++) {
			cin >> student[i];
		}

		// 2. 분노유발자 찾기 시작
		int cnt = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (student[i] <= student[j]) {
					break;
				}
				if (j == N - 1) {
					cnt++;
				}
			}
		}
		cout << cnt;
		return 0;
	}
}