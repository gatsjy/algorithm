#include <bits/stdc++.h>

using namespace std;

namespace _2 {

	int main() {
		// 1. 자연수 A,B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요
		int A, B;
		int sum = 0;
		cin >> A >> B;

		for (int i = A; i < B; i++) {
			sum += i;
			cout << i << " +";
		}
		sum += B;
		cout << B << " = ";
		cout << sum;
		return 0;
	}
}
