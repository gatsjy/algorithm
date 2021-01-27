#include <bits/stdc++.h>

using namespace std;
namespace _11967 {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	int n, m;
	int x, y, a, b;
	int board[101][101];
	int ch[101][101];
	vector<pair<int, int>> um[101][101]; // �̷��� �����ϴ� �ſ� ���ؼ� �� �����غ���!
	int cnt = 0;
	// ������ �� ����
	int countRooms() {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > 0) cnt++;
			}
		}
		return cnt;
	}

	// ���� �ڸ����� �� ų �� �ִ��� Ȯ���ϴ� �Լ�
	// �������� �� �� ���� ����� ���� ���� �Ŀ� �� �� �ֵ��� �ڵ��ؾ��Ѵ�..
	// �̷��� ����� �����ϱ� ���ؼ� �ϴ� �����״��� ���״��� üũ�ϰ�
	// ���� �ѹ��̶� ������ -> �ٽ� 0,0���� bfs����
	// �������� ���� �ܰ�� �Ѿ��
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
				bfs(0, 0); // �ѹ� ���� ������ �ٽ� bfs�� ������.
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

		// �ϴ� ó�� �κ� ���� Ų��.
		board[0][0] = 1;
		map<pair<int, int>, vector<pair<int, int>>>::iterator iter;
		bfs(0, 0);

		cnt = countRooms();

		cout << cnt;
		return 0;
	}
}