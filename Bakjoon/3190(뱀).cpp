#include <bits/stdc++.h>

using namespace std;

// 반례 모음 : https://www.acmicpc.net/board/view/56469
// 시계방향으로 돌아간다.
// 0 : 동, 1 : 남, 2 : 서, 3 : 북
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// 이동 방향 나타내는 변수
int dir = 0;

int N,K,L;

int board[102][102];

// 방향 전환을 나타내는 변수
queue<pair<int, char>> spin;

// 뱀의 구성요소를 나타내는 
// vector<{x좌표,y좌표}>
vector<pair<int, int>> snake;

// 끝났는지 체크하는 
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
	// 사과 할당
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}

	// 위치 변환 할당
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
	// 시작 세팅
	snake.push_back({ 0,0 });

	while (1) {
		bool endflag = false;
		time++;
		pair<int, int> cur = snake.back();

		// 다음 이동 위치
		int nx = cur.first + dx[dir];
		int ny = cur.second + dy[dir];

		// 다음 이동 위치 유효성 체크
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
		
		for (int i = 0; i < snake.size(); i++) {
			if (snake[i].first == nx && snake[i].second == ny) {
				endflag = true;
				break;
			}
		}

		// 위에서 만났으면 끝
		if (endflag) break;

		// 사과가 없다면 앞의 것을 뺀다.
		if (board[nx][ny] == 0) {
			snake.erase(snake.begin());
		}
		else // 사과가 있다면 사과를 먹은셈 친다.
		{
			board[nx][ny] = 0;
		}
		snake.push_back({ nx,ny });

		// 방향 변환에 걸리는지 체크
		// 방향 변환에 걸린다면 방향을 전환
		if (!spin.empty()) {
			if (spin.front().first == time) {
				if (spin.front().second == 'D') // 오른쪽
				{
					if (dir == 3) {
						dir = 0;
					}
					else {
						dir = dir + 1;
					}
				}
				else // spin.front().second == 'L' // 왼쪽
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