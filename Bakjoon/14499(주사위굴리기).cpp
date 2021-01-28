#include <bits/stdc++.h>

using namespace std;

int dice[4][3];
int ndice[4][3];

int board[21][21];
int x, y;
int k;
int n, m;

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
void takeMove(int dir) {
	if (dir == 1) {
		ndice[0][1] = dice[0][1];
		ndice[1][0] = dice[1][1];
		ndice[1][1] = dice[1][2];
		ndice[1][2] = dice[3][1];
		ndice[2][1] = dice[2][1];
		ndice[3][1] = dice[1][0];
	}
	else if (dir == 2) 
	{
		ndice[0][1] = dice[0][1];
		ndice[1][0] = dice[3][1];
		ndice[1][1] = dice[1][0];
		ndice[1][2] = dice[1][1];
		ndice[2][1] = dice[2][1];
		ndice[3][1] = dice[1][2];
	}
	else if (dir == 3) 
	{
		ndice[0][1] = dice[3][1];
		ndice[1][0] = dice[1][0];
		ndice[1][1] = dice[0][1];
		ndice[1][2] = dice[1][2];
		ndice[2][1] = dice[1][1];
		ndice[3][1] = dice[2][1];
	}
	else if (dir == 4)
	{
		ndice[0][1] = dice[1][1];
		ndice[1][0] = dice[1][0];
		ndice[1][1] = dice[2][1];
		ndice[1][2] = dice[1][2];
		ndice[2][1] = dice[3][1];
		ndice[3][1] = dice[0][1];
	}
	// 원하는 방향으로 옮긴 후에는 다시 dice에 넣어준다.
	dice[0][1] = ndice[0][1];
	dice[1][0] = ndice[1][0];
	dice[1][1] = ndice[1][1];
	dice[1][2] = ndice[1][2];
	dice[2][1] = ndice[2][1];
	dice[3][1] = ndice[3][1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> x >> y >>k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	while (k--) {
		int input;
		cin >> input;
		if (x + dx[input] < 0 || y + dy[input] < 0 || x + dx[input] >= n || y + dy[input] >= m) continue;
		x = x + dx[input];
		y = y + dy[input];
		takeMove(input);
		if (board[x][y] == 0) {
			dice[1][1] = 0;
		}
		else {
			dice[1][1] = board[x][y];
		}
		cout << dice[3][1] << "\n";
	}

	return 0;
}