#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <map>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/16929

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
char board[51][51];
int ch[51][51];
int dist[51][51]; // 이동한 거리를 체크
int n, m;
string s;

bool dfs(int x, int y, int cnt) {
    if (ch[x][y] > 0) {
        if (cnt - dist[x][y] >= 4) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        ch[x][y] = 1;
        dist[x][y] = cnt;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || nx >= m)continue;
            if (board[x][y] != board[nx][ny]) continue;
            cout << nx << ", " << ny << "\n";
            if (dfs(nx, ny, cnt + 1)) return true;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
        }
    }

    // ** 사이클을 이룬다는 개념을 어떻게 구현할 것인가?
    // 1. 일단 한바퀴 쭉 도는 것을 구현해보자.
    // dfs를 진행하면서 다시 돌아왔을 경우 사이클을 이룬다고 할 수 있음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ch[i][j] == 0) {
                //cout << "target " << i << " " << j << "\n";
                if (dfs(i, j, 0)) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";

    return 0;
}