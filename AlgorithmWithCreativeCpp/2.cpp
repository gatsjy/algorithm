#include <bits/stdc++.h>

using namespace std;

namespace _2 {

	int main() {
		// 1. �ڿ��� A,B�� �־����� A���� B������ ���� ���İ� �Բ� ����ϼ���
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
