#include <bits/stdc++.h>

using namespace std;

int board[10][10] = {};
// 0 : 동 / 1 : 서 / 2 : 남 / 3 : 북
vector<vector<int>> c1 = { {0},{1},{2},{3} };
vector<vector<int>> c2 = { {0,1},{2,3} };
vector<vector<int>> c3 = { {0,2},{0,3},{1,2},{1,3} };
vector<vector<int>> c4 = { {0,1,2},{0,1,3},{0,2,3},{1,2,3} };
vector<vector<int>> c5 = { {0,1,2,3} };

// 카메라의 방향에 대한
vector<vector<vector<int>>> camera{ {}
                                   ,{{0},{1},{2},{3}}
                                   ,{{0,1},{2,3}}
                                   ,{{0,2},{0,3},{1,2},{1,3}}
                                   ,{{0,1,2},{0,1,3},{0,2,3},{1,2,3}}
                                   ,{{0,1,2,3}}
};

vector<int> cnt(6);

int n, m;

struct cam {
    int x;
    int y;
    int number;
    cam(int a, int b, int c) {
        x = a;
        y = b;
        number = c;
    }
};

int func2(int x, int y, int dir) {
    int res = 0;
    if (dir == 0) {
        for (int i = y + 1; i < m; i++) {
            if (board[i][y] == 0) res++;
        }
    }
    else if (dir == 1) {
        for (int i = 0; i < y; i++) {
            if (board[i][y] == 0) res++;
        }
    }
    else if (dir == 2) {
        for (int i = x + 1; i < n; i++) {
            if (board[i][y] == 0) res++;
        }
    }
    else {
        for (int i = 0; i < x; i++) {
            if (board[i][y] == 0) res++;
        }
    }
    return res;
}

int func(cam c) {
    int max_size = -1;
    int max_idx = -1;
    for (int i = 0; i < camera[c.number].size(); i++) {
        int tmp_size = 0;
        for (int j = 0; j < camera[c.number][i].size(); j++) {
            // 동
            if (camera[c.number][i][j] == 0) {
                tmp_size = tmp_size + func2(c.x, c.y, 0);
            }
            // 서
            else if (camera[c.number][i][j] == 1) {
                tmp_size = tmp_size + func2(c.x, c.y, 1);
            }
            // 남
            else if (camera[c.number][i][j] == 2) {
                tmp_size = tmp_size + func2(c.x, c.y, 2);
            }
            // 북
            else // camera[c.number][i][j] == 3
            {
                tmp_size = tmp_size + func2(c.x, c.y, 3);
            }
        }
        if (max_size < tmp_size) {
            max_size = tmp_size;
            max_idx = i;
        }
    }
    return max_idx;
}

queue<cam> q;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            // 카메라 개수 세기
            if (board[i][j] > 0 && board[i][j] < 6) {
                q.push(cam(i, j, board[i][j]));
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int max_idx = func(cur);
        // max_idx대로 채우기
        for (int i = 0; i < camera[cur.number][max_idx].size(); i++) {
            int dir = camera[cur.number][max_idx][i];
            if (dir == 0) {
                for (int i = cur.y + 1; i < m; i++) {
                    if (board[i][cur.y] == 0) board[i][cur.y] = -1;
                }
            }
            else if (dir == 1) {
                for (int i = 0; i < cur.y; i++) {
                    if (board[i][cur.y] == 0) board[i][cur.y] = -1;
                }
            }
            else if (dir == 2) {
                for (int i = cur.x + 1; i < n; i++) {
                    if (board[cur.y][i] == 0) board[cur.y][i] = -1;
                }
            }
            else {
                for (int i = 0; i < cur.x; i++) {
                    if (board[cur.y][i] == 0) board[cur.y][i] = -1;
                }
            }
        }
    }

    return 0;
}