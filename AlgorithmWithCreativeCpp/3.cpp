#include <bits/stdc++.h>

using namespace std;

namespace _3 {

	int main() {
		// 1. N�� ������� ����϶�
		int N, sum = 1;
		cin >> N;

		cout << sum << " ";
		for (int i = 2; i < N; i++) {
			if (N % i == 0) {
				sum += i;
				cout << " + " << i;
			}
		}
		cout << " = " << sum;
		return 0;
	}
}