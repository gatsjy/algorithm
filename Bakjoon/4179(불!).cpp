#include <bits/stdc++.h>

using namespace std;

string board[1002];
int dist1[1002][1002]; // ���� ���� �ð�
int dist2[1002][1002]; // �������� ���� �ð�
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	// ����(��), ����(��)
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist1[i][j] = -1;
			dist2[i][j] = -1;
		}
	}
	queue<pair<int, int>> q1; // ���� �̵��� ���� ť
	queue<pair<int, int>> q2; // �������� �̵��� ���� ť
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				dist1[i][j] = 0;
				q1.push({ i,j });
			}
			if (board[i][j] == 'J') {
				dist2[i][j] = 0;
				q2.push({ i,j });
			}
		}
	}

	// ���� �̵��� ����Ѵ�.
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (board[xx][yy] == '#' || dist1[xx][yy] >= 0) continue;
			dist1[xx][yy] = dist1[cur.first][cur.second] + 1;
			q1.push({ xx,yy });
		}
	}

	// �������� Ż���� ����Ѵ�.
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist2[xx][yy] >= 0) continue;
			if (board[xx][yy] == '#') continue;
			// ������ ���� ���� ���� ������ ���� ���Ѵ�. (�����ִٴ� ���� ���� ���� ���� �ð����� ���� �ִ�.)
			// ���� ������ �ϴ� ���� �ʰ� ���纸�� ũ�� �̹� �װ��� ���� ������ �ڸ���� ��
			// �� �� �ʰ� �� ���ƾ� �Ѵ�. -> �� ���� �����ߴٴ� ��
			if (dist1[xx][yy] != -1 && dist1[xx][yy] <= dist2[cur.first][cur.second] + 1) continue;
			q2.push({ xx,yy });
			dist2[xx][yy] = dist2[cur.first][cur.second] + 1;
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}