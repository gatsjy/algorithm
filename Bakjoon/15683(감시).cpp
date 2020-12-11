#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int board[10][10] = {};
int board2[10][10] = {};
int rboard[10][10] = {};

struct cam {
    int x;
    int y;
    int number;
    cam(int a, int b, int c) {
        x = a;
        y = b;
        number = c;
    }
    bool operator<(const cam& b) const {
        return y < b.y;
    }
};

// 1. 1�������� queue�� �����ϱ� ������ -> ���Ʈ ������ �̿��ؼ� ������ �ʿ伺�� ����..
// 2. �ϴ� priority queue�� �������� ���? -> ���� �̰Ŵ� ������ ���δ� ����������...
// 3. dfs�� ��� ����� ���� ��� Ž���ؾ���..
priority_queue<cam> q;
queue<cam> q2;
// 0 : �� / 1 : �� / 2 : �� / 3 : ��
// ī�޶��� ���⿡ ����
vector<vector<vector<int>>> camera{ {}
                           ,{{0},{1},{2},{3}}
                           ,{{0,1},{2,3}}
                           ,{{0,2},{0,3},{1,2},{1,3}}
                           ,{{0,1,2},{0,1,3},{0,2,3},{1,2,3}}
                           ,{{0,1,2,3}}
};

int n, m;

vector<vector<cam>> cameraCnt(6);


int func2(int x, int y, int dir) {
    int res = 0;
    // ��
    if (dir == 0) {
        for (int i = y + 1; i < m; i++) {
            if (board[x][i] == 0) {
                res++;
            }
            else if (board[x][i] == 6) {
                break;
            };
        }
    }
    // ��
    else if (dir == 1) {
        for (int i = y - 1; i >= 0; i--) {
            if (board[x][i] == 0) {
                res++;
            }
            else if (board[x][i] == 6) {
                break;
            }
        }
    }
    // ��
    else if (dir == 2) {
        for (int i = x + 1; i < n; i++) {
            if (board[i][y] == 0) {
                res++;
            }
            else if (board[i][y] == 6) {
                break;
            }
        }
    }
    // ��
    else {
        for (int i = x - 1; i >= 0; i--) {
            if (board[i][y] == 0) {
                res++;
            }
            else if (board[i][y] == 6) {
                break;
            }
        }
    }
    return res;
}

// ���� ������ �̵��� ã�� ����
int func(cam c) {
    int max_size = -1;
    int max_idx = -1;
    for (int i = 0; i < camera[c.number].size(); i++) {
        int tmp_size = 0;
        for (int j = 0; j < camera[c.number][i].size(); j++) {
            // ��
            if (camera[c.number][i][j] == 0) {
                tmp_size = tmp_size + func2(c.x, c.y, 0);
            }
            // ��
            else if (camera[c.number][i][j] == 1) {
                tmp_size = tmp_size + func2(c.x, c.y, 1);
            }
            // ��
            else if (camera[c.number][i][j] == 2) {
                tmp_size = tmp_size + func2(c.x, c.y, 2);
            }
            // ��
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


int max_res = 2147000000;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rboard[i][j];
            // ī�޶� ���� ����
            if (rboard[i][j] > 0 && rboard[i][j] < 6) {
                //q.push(cam(i, j, board[i][j]));
                cameraCnt[rboard[i][j]].push_back(cam(i, j, rboard[i][j]));
            }
        }
    }

    sort(cameraCnt.begin(), cameraCnt.end());

    do {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = rboard[i][j];
                board2[i][j] = rboard[i][j];
            }
        }

        while (!q.empty()) q.pop();
        while (!q2.empty()) q2.pop();

        for (int i = 0; i < cameraCnt.size(); i++) {
            for (int j = 0; j < cameraCnt[i].size(); j++) {
                q.push(cameraCnt[i][j]);
                q2.push(cameraCnt[i][j]);
            }
        }

        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            int max_idx = func(cur);
            // max_idx��� ä���
            for (int i = 0; i < camera[cur.number][max_idx].size(); i++) {
                int dir = camera[cur.number][max_idx][i];
                int x = cur.x;
                int y = cur.y;
                if (dir == 0) {
                    for (int i = y + 1; i < m; i++) {
                        if (board[x][i] == 0) {
                            board[x][i] = -1;
                        }
                        else if (board[x][i] == 6) {
                            break;
                        }
                    }
                }
                // ������ġ�� �������� �������� �̵�
                else if (dir == 1) {
                    for (int i = y - 1; i >= 0; i--) {
                        if (board[x][i] == 0) {
                            board[x][i] = -1;
                        }
                        else if (board[x][i] == 6) {
                            break;
                        }
                    }
                }
                // ������ġ�� �������� �������� �̵�
                else if (dir == 2) {
                    for (int i = x + 1; i < n; i++) {
                        if (board[i][y] == 0) {
                            board[i][y] = -1;
                        }
                        else if (board[i][y] == 6) {
                            break;
                        }
                    }
                }
                // ������ġ�� �������� �ϩP���� �̵�
                else {
                    for (int i = x - 1; i >= 0; i--) {
                        if (board[i][y] == 0) {
                            board[i][y] = -1;
                        }
                        else if (board[i][y] == 6) {
                            break;
                        }
                    }
                }
            }
        }


        // ��� ��..
        while (!q2.empty()) {
            auto cur = q2.front(); q2.pop();
            int max_idx = func(cur);
            // max_idx��� ä���
            for (int i = 0; i < camera[cur.number][max_idx].size(); i++) {
                int dir = camera[cur.number][max_idx][i];
                int x = cur.x;
                int y = cur.y;
                if (dir == 0) {
                    for (int i = y + 1; i < m; i++) {
                        if (board2[x][i] == 0) {
                            board2[x][i] = -1;
                        }
                        else if (board2[x][i] == 6) {
                            break;
                        }
                    }
                }
                // ������ġ�� �������� �������� �̵�
                else if (dir == 1) {
                    for (int i = y - 1; i >= 0; i--) {
                        if (board2[x][i] == 0) {
                            board2[x][i] = -1;
                        }
                        else if (board[x][i] == 6) {
                            break;
                        }
                    }
                }
                // ������ġ�� �������� �������� �̵�
                else if (dir == 2) {
                    for (int i = x + 1; i < n; i++) {
                        if (board2[i][y] == 0) {
                            board2[i][y] = -1;
                        }
                        else if (board2[i][y] == 6) {
                            break;
                        }
                    }
                }
                // ������ġ�� �������� �ϩP���� �̵�
                else {
                    for (int i = x - 1; i >= 0; i--) {
                        if (board2[i][y] == 0) {
                            board2[i][y] = -1;
                        }
                        else if (board2[i][y] == 6) {
                            break;
                        }
                    }
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    cnt++;
                }
            }
        }

        int cnt2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board2[i][j] == 0) {
                    cnt2++;
                }
            }
        }

        //cout << cnt << "\n";
        if (max_res > cnt) {
            max_res = cnt;
        }

        if (max_res > cnt2) {
            max_res = cnt2;
        }

    } while (next_permutation(cameraCnt.begin(), cameraCnt.end()));

    cout << max_res;
    return 0;
}