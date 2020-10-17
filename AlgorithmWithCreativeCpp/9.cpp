#include <bits/stdc++.h>

using namespace std;

namespace _9 {
	int cnt[50001] = { 0, };
	// 1. 아래의 함수를 쓰면 타임 리밋이 난다. 
	int countDivisor(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) cnt++;
		}
		return cnt;
	}

	// 2. 그렇다면 어떻게 써야 할까?
	// 하나하나 전부 넣기 시작한다.
	void main() {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j = i + j) {
				cnt[j]++;
			}
		}
		for (int i = 1; i <= N; i++) {
			cout << cnt[i] << " ";
		}
	}
}