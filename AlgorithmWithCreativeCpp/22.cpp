#include <bits/stdc++.h>

using namespace std;

namespace _22 {
	int main() {
		int N, K;
		cin >> N >> K;
		int answer = -2147000000;

		vector<int> temp(N);
		for (int i = 0; i < N; i++) {
			cin >> temp[i];
		}

		int sum = 0;
		for (int i = 0; i < K; i++) {
			sum += temp[i];
		}
		answer = sum;

		for (int i = K; i < N; i++) {
			sum = sum - temp[i - K] + temp[i];
			answer = max(sum, answer);
		}
		cout << answer;
		return 0;
	}
}