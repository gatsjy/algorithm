#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

namespace _16973 {
    // ���� 0 -> ��, ��, ��, ��
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };
    int board[1001][1001];
    int ch[1001][1001];
    int n, m, h, w, sx, sy, fx, fy;

    //�Է����� �־��� ���簢���� �������� ����� �ʰ�, ���簢���� ���� �ִ� ĭ���� ���� ����. -> ������ �̰� ��Ʈ�̴�.
    // ���� ���� �ſ��� ���ٸ� ������ �ٲٸ� ���?
    bool isokay(int x, int y, int dir) {
        if (dir == 0) {
            // dir = 1 -> ��
            for (int i = y; i < y + w; i++) {
                if (board[x][i] == 1) return false;
            }
        }
        else if (dir == 2)
        {
            // dir = 2 -> ��
            int nx = x + h - 1;
            if (nx > n - 1) return false;
            for (int i = y; i < y + w; i++) {
                if (board[nx][i] == 1) return false;
            }
        }
        else if (dir == 1)
        {
            // dir = 1 -> ��
            int ny = y + w - 1;
            if (ny > m - 1) return false;
            for (int i = x; i < x + h; i++) {
                if (board[i][ny] == 1) return false;
            }
        }
        else if (dir == 3)
        {
            // dir == 3 -> ��
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
            // ���ϴ� ���� �����ߴ��� Ȯ��
            if (x == fx && y == fy) {
                cout << ch[x][y] - 1;
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx > n - h || yy > m - w) continue;
                // �簢�� ���ο� ���� �ֳ� Ȯ��
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