#include <iostream>

using namespace std;

namespace _1 {
	int main() {
		int N, M;
		cin >> N >> M;
		int sum = 0;
		// 1. 1���� N������ �� �� M�� ������� ����϶�
		for (int i = 1; i <= N; i++) {
			if (i % M == 0) sum += i;
		}
		cout << sum;
		return 0;
	}
}
