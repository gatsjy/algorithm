#include <iostream>

using namespace std;

namespace _1 {
	int main() {
		int N, M;
		cin >> N >> M;
		int sum = 0;
		// 1. 1부터 N까지의 수 중 M의 배수합을 출력하라
		for (int i = 1; i <= N; i++) {
			if (i % M == 0) sum += i;
		}
		cout << sum;
		return 0;
	}
}
