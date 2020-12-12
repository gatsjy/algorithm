#include <bits/stdc++.h>

using namespace std;

int board[10][10] = {};
int rboard[10][10] = {};

// 1. 1�������� queue�� �����ϱ� ������ -> ���Ʈ ������ �̿��ؼ� ������ �ʿ伺�� ����..
// 2. �ϴ� priority queue�� �������� ���? -> ���� �̰Ŵ� ������ ���δ� ����������...
// 3. dfs�� ��� ����� ���� ��� Ž���ؾ���..
// 4. �ذ�.. ��� ������

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

int func2(int x, int y, int dir) {
    int res = 0;
    // ��
    if (dir == 0) {
        for (int i = y + 1; i < m; i++) {
            if (board[x][i] == 0) {
                board[x][i] = -1;
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
                board[x][i] = -1;
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
                board[i][y] = -1;
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
                board[i][y] = -1;
            }
            else if (board[i][y] == 6) {
                break;
            }
        }
    }
    return res;
}

vector<pair<int, pair<int, int>>> cameras;
int ch[8] = { 0, };

int max_res = 2147000000;

void dfs(int level)
{
    if (level == cameras.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = rboard[i][j];
            }
        }

        for (int i = 0; i < cameras.size(); i++) {
            for (int j = 0; j < camera[cameras[i].first][ch[i]].size(); j++) {
                func2(cameras[i].second.first, cameras[i].second.second, camera[cameras[i].first][ch[i]][j]);
            }
        }

        int cnt = 0;

        // ��� ����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    cnt++;
                }
            }
        }

        if (max_res > cnt) {
            max_res = cnt;
        }
    }
    else {
        for (int i = 0; i < camera[cameras[level].first].size(); i++) {
            if (ch[level] == -1) {
                ch[level] = i;
                dfs(level + 1);
                ch[level] = -1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rboard[i][j];
            if (rboard[i][j] > 0 && rboard[i][j] < 6) {
                cameras.push_back({ rboard[i][j],{i,j} });
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        ch[i] = -1;
    }

    dfs(0);

    cout << max_res;
}