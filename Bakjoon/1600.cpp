#include <iostream>
#include <queue>

using namespace std;

namespace _1600 {
    int dy[4] = { 1,0,-1,0 };
    int dx[4] = { 0,1,0,-1 };
    int horsey[8] = { 2,1,-1,-2,-2,-1,1,2 };
    int horsex[8] = { 1,2,2,1,-1,-2,-2,-1 };

    int k, w, h;

    int map[201][201];
    int ch[201][201];

    int main() {
        cin >> k >> w >> h;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> map[i][j];
            }
        }
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        ch[0][0] = 1;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = cur.second + dx[i];
                int yy = cur.first + dy[i];
                if (xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
                if (ch[yy][xx] == 1 && k > 0) {
                    for (int j = 0; j < 8; j++) {
                        yy += horsey[j];
                        xx += horsex[j];
                        if (xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
                        if (map[yy][xx] == 1) continue;
                        ch[yy][xx] = ch[cur.first][cur.second] + 1;
                        q.push({ yy,xx });
                        k--;
                    }
                }
                else {
                    continue;
                }
                map[yy][xx] = map[cur.first][cur.second] + 1;
                ch[yy][xx] = 1;
                q.push({ yy,xx });
            }
        }
        return 0;
    }
}