#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

namespace _16973 {
    // 현재 0 -> 북, 동, 남, 서
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };
    int board[1001][1001];
    int ch[1001][1001];
    int n, m, h, w, sx, sy, fx, fy;

    //입력으로 주어진 직사각형은 격자판을 벗어나지 않고, 직사각형이 놓여 있는 칸에는 벽이 없다. -> 문제중 이게 힌트이다.
    // 전부 보는 거에서 한줄만 보도록 바꾸면 어떨까?
    bool isokay(int x, int y, int dir) {
        if (dir == 0) {
            // dir = 1 -> 북
            for (int i = y; i < y + w; i++) {
                if (board[x][i] == 1) return false;
            }
        }
        else if (dir == 2)
        {
            // dir = 2 -> 남
            int nx = x + h - 1;
            if (nx > n - 1) return false;
            for (int i = y; i < y + w; i++) {
                if (board[nx][i] == 1) return false;
            }
        }
        else if (dir == 1)
        {
            // dir = 1 -> 동
            int ny = y + w - 1;
            if (ny > m - 1) return false;
            for (int i = x; i < x + h; i++) {
                if (board[i][ny] == 1) return false;
            }
        }
        else if (dir == 3)
        {
            // dir == 3 -> 서
            for (int i = x; i < x + h; i++) {
                if (board[i][y] == 1) return false;
            }
        }
        return true;
    }

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        cin >> h >> w >> sx >> sy >> fx >> fy;
        sx--; sy--; fx--; fy--;
        queue<pair<int, int>> q;
        q.push({ sx,sy });
        ch[sx][sy] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // 원하는 점에 도착했는지 확인
            if (x == fx && y == fy) {
                cout << ch[x][y] - 1;
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx > n - h || yy > m - w) continue;
                // 사각형 내부에 벽이 있나 확인
                if (!isokay(xx, yy, i)) continue;
                if (ch[xx][yy] > 0) continue;
                q.push({ xx,yy });
                ch[xx][yy] = ch[x][y] + 1;
            }
        }

        cout << -1;
        return 0;
    }
}