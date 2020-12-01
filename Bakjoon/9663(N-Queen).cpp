#include <bits/stdc++.h>

using namespace std;

namespace _9663{
	int ch1[40];
	int ch2[40];
	int ch3[40];
	int N;
	int cnt = 0;
	void dfs(int cur) {
		if (cur == N) {
			cnt++;
			return;
		}
		for (int i = 0; i < N; i++) {
			if (ch1[i] == 1 || ch2[i + cur] == 1 || ch3[cur - i + N - 1] == 1)continue;
			ch1[i] = 1;
			ch2[i + cur] = 1;
			ch3[cur - i + N - 1] = 1;
			dfs(cur + 1);
			ch1[i] = 0;
			ch2[i + cur] = 0;
			ch3[cur - i + N - 1] = 0;
		}
	}

	int main() {
		cin >> N;
		dfs(0);
		cout << cnt;
		return 0;
	}
}
