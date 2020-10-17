#include <bits/stdc++.h>

using namespace std;

namespace _18 {
	int main() {
		vector<int> noise;
		int N, M;
		cin >> N >> M;
		int answer = -1;
		int cnt = 0;
		int input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			noise.push_back(input);
		}
		for (int i = 0; i < noise.size(); i++) {
			if (noise[i] > M) {
				cnt++;
			}
			else if (noise[i] <= M) {
				cnt = 0;
			}
			// 이거를 조심하자. 항상 체크해야하는 부분인데 나는 M이 작을때만 판단한 거였다.
			answer = max(cnt, answer);
		}
		cout << answer;
		return 0;
	}
}