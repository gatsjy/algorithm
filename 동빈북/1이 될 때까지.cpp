#include <bits/stdc++.h>

using namespace std;

namespace _1이_될_때까지 {
	int n, k;
	int result;

	int main() {
		cin >> n >> k;
		while (1) {
			int target = (n / k) * k; // 왜냐하면 -1 씩 빼주는데 해당 하는 값까지 도달해야한다.
			result += (n - target);
			// N이 K보다 작을때 반복문 탈출
			if (n < k) break;
			result++;
			n /= k;
		}
		result += (n - 1);
		cout << result;
		return 0;
	}
}