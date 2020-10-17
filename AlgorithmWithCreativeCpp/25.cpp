#include <bits/stdc++.h>

using namespace std;

namespace _25 {
	int main() {
		int N;
		cin >> N;

		vector<int> score(N);

		for (int i = 0; i < N; i++) {
			cin >> score[i];
		}

		for (int i = 0; i < N; i++) {
			int rank = 0;
			for (int j = 0; j < N; j++) {
				if (score[i] < score[j]) {
					rank++;
				}
			}
			cout << rank + 1 << " ";
		}
		return 0;
	}
}
