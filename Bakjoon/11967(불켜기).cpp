#include <bits/stdc++.h>

using namespace std;
namespace _11967 {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	int n, m;
	int x, y, a, b;
	int board[101][101];
	int ch[101][101];
	vector<pair<int, int>> um[101][101]; // 이렇게 선언하는 거에 대해서 잘 생각해보기!
	int cnt = 0;
	// 불켜진 방 세기
	int countRooms() {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > 0) cnt++;
			}
		}
		return cnt;
	}

	// 현재 자리에서 불 킬 수 있는지 확인하는 함수
	// 이전에는 갈 수 없던 방들이 불이 켜진 후엔 갈 수 있도록 코딩해야한다..
	// 이러한 방법을 구현하기 위해서 일단 불을켰는지 안켰는지 체크하고
	// 불을 한번이라도 켰으면 -> 다시 0,0부터 bfs시작
	// 안켰으면 다음 단계로 넘어간다
	bool lightUp(int x, int y) {
		bool flag = false;
		for (int i = 0; i < um[x][y].size(); i++) {
			if (board[um[x][y][i].first][um[x][y][i].second] == 0) {
				board[um[x][y][i].first][um[x][y][i].second] = 1;
				flag = true;
			}
		}
		return flag;
	}

	void bfs(int x, int y) {
		queue<pair<int, int>> q;
		memset(ch, 0, sizeof(ch));
		q.push({ 0,0 });
		ch[0][0] = 1;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (lightUp(x, y)) {
				bfs(0, 0); // 한번 불을 켰으면 다시 bfs를 돌린다.
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (ch[nx][ny] > 0) continue;
				if (board[nx][ny] == 0) continue;
				ch[nx][ny] = ch[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> a >> b;
			um[--x][--y].push_back({ --a,--b });
		}

		// 일단 처음 부분 불을 킨다.
		board[0][0] = 1;
		map<pair<int, int>, vector<pair<int, int>>>::iterator iter;
		bfs(0, 0);

		cnt = countRooms();

		cout << cnt;
		return 0;
	}
}