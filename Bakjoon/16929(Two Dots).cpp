#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <map>
#include <string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
char board[51][51];
int ch[51][51];
int n, m;
string s;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || nx >= m)continue;
        if (board[x][y] != board[nx][ny]) continue;
        if (ch[nx][ny] > 0) continue;
        ch[nx][ny] = 1;
        cout << nx << ", " << ny << " ";
        dfs(nx, ny);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // 사이클을 이룬다는 개념을 어떻게 구현할 것인가?
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
        }
    }

    // 1. 일단 한바퀴 쭉 도는 것을 구현해보자.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(ch, 0, sizeof(ch));
            dfs(i, j);
            cout << "\n";
        }
    }

    return 0;
}