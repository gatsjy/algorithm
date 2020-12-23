#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, m, cnt;
int board[302][302];

// 0 : 남, 1 : 동, 2 : 북, 3 : 서
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag = true;
// x,y 위치, 
void dfs(int x, int y, int dir, int next, int gSeq) {

    int cur = board[x][y];
    board[x][y] = next;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    // 만약 방향이 '서'이고 원위치로 돌아온 경우 return
    if ((dir == 3 && (x == gSeq && y == gSeq)) || dir >=4) {
        return;
    };

    // 움직인다면 세로인 경우는 nx + n - gSeq 까지 이동가능, 가로는 ny + m - gSeq까지 이동가능
    // 남, 동, 북은 위 조건식으로 잡을 수 있지만, 서에서 북에서 서로 꺾을때는 잡지 못함.
    if (nx > (n - gSeq - 1) || ny > (m - gSeq - 1) || nx < 0 || ny < 0)
    {
        nx = x + dx[dir + 1];
        ny = y + dy[dir + 1];
        dfs(nx, ny, dir + 1, cur, gSeq);
    }
    else {
        dfs(nx, ny, dir, cur, gSeq);
    }
}

int main() {
    cin >> n >> m >> cnt;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 이제 케이스 수 만큼 배열 회전시키기
    // * 케이스의 그룹이 한단계 한단계 깊어질수록 시작 위치는 (1,1)씩 증가한다.
    // ** (0,0)에서 시작하면 한바퀴를 돌고난 후에 (0,0)으로 돌아온다.
    while (cnt--) {
        // 그릅 수 만큼 dfs를 돌린다.
        for (int i = 0; i < n / 2; i++) {
        //for (int i = 0; i <= min(n, m) / 2; i++) {
            dfs(i, i, 0, board[i][i+1], i); // 처음 시작은 무조건 남으로 긔
        }
    }

    // 정답 관련 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}