#include <bits/stdc++.h>

using namespace std;

// �ݷ� ���� : https://www.acmicpc.net/board/view/56469
// �ð�������� ���ư���.
// 0 : ��, 1 : ��, 2 : ��, 3 : ��
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// �̵� ���� ��Ÿ���� ����
int dir = 0;

int N,K,L;

int board[102][102];

// ���� ��ȯ�� ��Ÿ���� ����
queue<pair<int, char>> spin;

// ���� ������Ҹ� ��Ÿ���� 
// vector<{x��ǥ,y��ǥ}>
vector<pair<int, int>> snake;

// �������� üũ�ϴ� 
bool isEnd() {
	int x = snake.back().first;
	int y = snake.back().second;
	if (x < 0 || y < 0 || x >= N || y >= N) return true;
	for (int i = 0; i < snake.size(); i++) {
		if (snake[i].first == x && snake[i].second) {
			return true;
		}
	}
	return false;
}

int main() {
	cin >> N >> K;
	// ��� �Ҵ�
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}

	// ��ġ ��ȯ �Ҵ�
	cin >> L;
	for (int i = 0; i < L; i++) {
		int cnt; char c;
		cin >> cnt >> c;
		pair<int, char> input;
		input.first = cnt;
		input.second = c;
		spin.push(input);
	}

	int time = 0;
	// ���� ����
	snake.push_back({ 0,0 });

	while (1) {
		bool endflag = false;
		time++;
		pair<int, int> cur = snake.back();

		// ���� �̵� ��ġ
		int nx = cur.first + dx[dir];
		int ny = cur.second + dy[dir];

		// ���� �̵� ��ġ ��ȿ�� üũ
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
		
		for (int i = 0; i < snake.size(); i++) {
			if (snake[i].first == nx && snake[i].second == ny) {
				endflag = true;
				break;
			}
		}

		// ������ �������� ��
		if (endflag) break;

		// ����� ���ٸ� ���� ���� ����.
		if (board[nx][ny] == 0) {
			snake.erase(snake.begin());
		}
		else // ����� �ִٸ� ����� ������ ģ��.
		{
			board[nx][ny] = 0;
		}
		snake.push_back({ nx,ny });

		// ���� ��ȯ�� �ɸ����� üũ
		// ���� ��ȯ�� �ɸ��ٸ� ������ ��ȯ
		if (!spin.empty()) {
			if (spin.front().first == time) {
				if (spin.front().second == 'D') // ������
				{
					if (dir == 3) {
						dir = 0;
					}
					else {
						dir = dir + 1;
					}
				}
				else // spin.front().second == 'L' // ����
				{
					if (dir == 0) {
						dir = 3;
					}
					else {
						dir = dir - 1;
					}
				}
				spin.pop();
			}
		}
	}

	cout << time;
	return 0;
}