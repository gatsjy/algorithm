#include <bits/stdc++.h>

using namespace std;

namespace _12{
	int main() {
		// 수가 많아지면 어떻게 해결해야 할까?
		// 1. 먼저 들어온 값의 자릿수를 확인한다.
		int n, cnt = 0;
		cin >> n;
		int digitCnt = to_string(n).size();

		// 2. 자릿수의 이전까지를 계산
		for (int i = 1; i < digitCnt; i++) {
			cnt += i * (9 * pow(10, i - 1));
		}

		// 3. 해당 자릿수의 값을 계산
		cnt += digitCnt * (n - pow(10, digitCnt - 1) + 1);
		cout << cnt;

		return 0;
	}
}