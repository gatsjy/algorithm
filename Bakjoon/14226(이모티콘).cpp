#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// ch[disp][clip]
int ch[1002][1002];

int n;
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	// ch에 있는 값 초기화
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			ch[i][j] = -1;
		}
	}

	// ch에 기본 값 할당 
	ch[1][0] = 0;
	ch[1][1] = 1;

	// q에 첫 위치 푸시
	q.push({ 1,1 });

	// bfs 돌리기
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 3; i++) {
			// next disp, next clip
			int ndisp = 0;
			int nclip = 0;
			if (i == 0) {
				// 화면의 모든 이모티콘을 저장해서 클립보드로 옮김
				ndisp = cur.first;
				nclip = ndisp;
			}
			else if (i == 1) {
				// 클립보드에 있는 이모티콘을 화면에 붙인다.
				ndisp = cur.first + cur.second;
				nclip = cur.second;
			}
			else // i == 2
			{
				// 화면에 있는 이모티콘 하나를 삭제한다.
				ndisp = cur.first - 1;
				nclip = cur.second;
			}
			if (ndisp < 1 || ndisp > 1000) continue;
			if (ch[ndisp][nclip] > 0) continue;
			ch[ndisp][nclip] = ch[cur.first][cur.second] + 1;
			q.push({ ndisp,nclip });
		}
	}

	int res = 2147000000;
	for (int i = 1; i < 1001; i++) {
		if (res > ch[i][n]) res = ch[i][n];
	}

	cout << res - 1;

	return 0;
}