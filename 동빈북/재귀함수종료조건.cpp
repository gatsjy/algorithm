#include <bits/stdc++.h>

using namespace std;

namespace _재귀함수종료조건 {
	void dfs(int n) {
		if (n == 3) {
			cout << "재귀끝" << "\n";
			return;
		}
		cout << n << "재귀에서" << n + 1 << "을호출합니다." << "\n";
		dfs(n + 1);
		cout << n << "번째 재귀 끝" << "\n";
	}

	int main() {
		dfs(0);
		return 0;
	}
}
