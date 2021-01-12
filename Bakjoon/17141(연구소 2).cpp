#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace _17141 {
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };
    int n, m;

    vector<vector<int>> board;
    vector<int> virus;
    vector<int> a;
    vector<int> ch;
    int min_res = 2147000000;

    int isValid(vector<vector<int>> tmp) {
        int res = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp[i][j] == 0) {
                    return -1;
                }
                if (tmp[i][j] > res) {
                    res = tmp[i][j];
                }
            }
        }
        return res;
    }
    void spread(vector<vector<int>> tmp, vector<int> a) {
        // 바이러스 할당 작업 긔
        queue<pair<int, int>> q;
        //vector<vector<int>> ch = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < a.size(); i++) {
            tmp[a[i] / n][a[i] % n] = 2;
            q.push({ a[i] / n , a[i] % n });
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (tmp[nx][ny] > 0) continue;
                tmp[nx][ny] = tmp[x][y] + 1;
                q.push({ nx,ny });
            }
        }

        int res = isValid(tmp);

        //cout << res << "\n";
        if (res != -1) {
            min_res = min(min_res, res - 2);
        }
    }

    void dfs(int n) {
        if (a.size() == m) {
            //for (int i = 0; i < a.size(); i++) {
            //    cout << a[i] << " ";
            //}
            //cout << "\n";
            spread(board, a);
        }
        else {
            for (int i = n; i < virus.size(); i++) {
                if (ch[i] == 0) {
                    a.push_back(virus[i]);
                    ch[i] = 1;
                    dfs(i + 1);
                    a.pop_back();
                    ch[i] = 0;
                }
            }
        }
    }
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        cin >> n >> m;

        board = vector<vector<int>>(n, vector<int>(n, 0));

        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if (board[i][j] == 2) {
                    virus.push_back(idx);
                    board[i][j] = 0;
                }
                idx++;
            }
        }

        ch.resize(virus.size());
        dfs(0);

        if (min_res == 2147000000) {
            cout << -1;
        }
        else {
            cout << min_res;
        }
        return 0;
    }
}