#include <iostream>
#include <queue>

using namespace std;

namespace _1600 {
    int dy[4] = { 1,0,-1,0 };
    int dx[4] = { 0,1,0,-1 };
    int hdy[8] = { -2,-1,1,2,2,1,-1,-2 };
    int hdx[8] = { 1, 2,2,1,-1,-2,-2,-1 };

    int k, w, h;

    int map[201][201];
    int ch[201][201][31] = { 0 };

    struct pos {
        int x;
        int y;
        int k;
        int cnt;
        pos(int a, int b, int c, int d) : x(a), y(b), k(c), cnt(d) {}
    };

    int bfs(int k) {
        queue<pos> q;
        q.push(pos(0, 0, k, 0));

        while (!q.empty()) {
            pos cur = q.front();
            q.pop();

            // hy,wx ¿Ü¿ì±â..
            if (cur.x < 0 || cur.y < 0 || cur.x >= w || cur.y >= h) continue;
            if (map[cur.y][cur.x]) continue;

            if (cur.x == w - 1 && cur.y == h - 1) {
                return cur.cnt;
            }

            if (ch[cur.y][cur.x][cur.k]) continue;
            ch[cur.y][cur.x][cur.k] = 1;
            for (int i = 0; i < 4; i++) {
                int yy = cur.y + dy[i];
                int xx = cur.x + dx[i];
                q.push(pos(xx, yy, cur.k, cur.cnt + 1));
            }
            if (cur.k == 0) continue;
            for (int i = 0; i < 8; i++) {
                int yy = cur.y + hdy[i];
                int xx = cur.x + hdx[i];
                q.push(pos(xx, yy, cur.k - 1, cur.cnt + 1));
            }
        }
        return -1;
    }

    int main() {
        cin >> k >> w >> h;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        cout << bfs(k);

        return 0;
    }
}
