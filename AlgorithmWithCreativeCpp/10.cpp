#include <bits/stdc++.h>

using namespace std;

namespace _10 {
	int digit_sum(int x) {
		int sum = 0;
		while (x > 0) {
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}

	int main() {
		int N;
		cin >> N;
		priority_queue<pair<int, int>> pq;

		int input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			pq.push({ digit_sum(input), input });
		}
		cout << pq.top().second;
		return 0;
	}
}