#include <bits/stdc++.h>

using namespace std;

#define MAX 501

namespace _2458 {
	int ch[MAX][MAX];
	int n, m, a, b;

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			ch[a][b] = 1; // 서로서로 연결해준다. -> 이 말의 뜻은 a < b 라는 뜻이다.
		}

		// 학생의 순위를 알고 싶으면, 자기보다 작은사람과 자기보다 큰사람의 수를 세었을때 n-1이 되어야한다.
		// 예를들면, 총 7명 중에서 자기보다 작은사람이 4명이고 자기보다 큰사람이 2명이라면 앞에서 3등이다.
		// 이러한 점을 알고 싶으면 모든 경우의 수를 따져가면서 자기보다 큰사람, 자기보다 작은사람을 찾아야 문제를 풀 수 있다.
		// 왜 모든 경우의 수를 비교해 보면 알수 있을까?
		// 예를들어, 한주안(student) 가 키가 170이고 i(한상인)은 160 j(한상진)은 170이라고 해보자
		// ch[i][j] = 1을 만들기 위해서는 한상인 < 한주안 < 한상진 이라는 결과가 나와야
		// 한상인 < 한상진 즉, ch[i][j]를 만들 수 있다.
		for (int student = 1; student <= n; student++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (ch[i][student] && ch[student][j]) {
						ch[i][j] = 1;
					}
				}
			}
		}
		int res = 0;
		for (int student = 1; student <= n; student++) {
			int bigger = 0; int smaller = 0;
			for (int i = 1; i <= n; i++) {
				if (student == i) continue;
				// 1. 나보다 작은 사람 찾기
				if (ch[i][student]) bigger++;
				// 2. 나보다 큰사람 찾기
				if (ch[student][i]) smaller++;
			}
			// 나보다 작은사람 + 나보다 큰사람 했을때 n-1(자신을뺀나머지)라면 순위를 알 수 있는 경우
			if (bigger + smaller == n - 1) res++;
		}
		cout << res;
		return 0;
	}
}