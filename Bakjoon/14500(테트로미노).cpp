#include <bits/stdc++.h>

using namespace std;

namespace _14500 {
    // 반례 모음 https://www.acmicpc.net/board/view/55687

    int board[502][502];

    int n, m;
    // 4*1 -> 1개
    vector<pair<int, int>> fourbyone = { {0,0},{0,1},{0,2},{0,3} };

    // 1*4 -> 1개
    vector<pair<int, int>> onebyfour = { {0,0},{1,0},{2,0},{3,0} };

    // 2*2 -> 1개
    vector<pair<int, int>> twobytwo = { {0,0},{0,1},{1,0},{1,1} };

    // 3*2 -> 8개
    vector<vector<pair<int, int>>> threebytwo = { {{0,0},{0,1},{0,2},{1,0}}
                                                 ,{{0,0},{0,1},{0,2},{1,1}}
                                                 ,{{0,0},{0,1},{0,2},{1,2}}
                                                 ,{{0,0},{1,0},{1,1},{1,2}}
                                                 ,{{0,1},{1,0},{1,1},{1,2}}
                                                 ,{{0,2},{1,0},{1,1},{1,2}}
                                                 ,{{1,0},{1,1},{0,1},{0,2}}
                                                 ,{{0,0},{0,1},{1,1},{1,2}} };

    // 2*3 -> 8개
    vector<vector<pair<int, int>>> twobythree = { { {0,0},{0,1},{1,0},{2,0}}
                                                , { {0,0},{1,0},{1,1},{2,0}}
                                                , { {0,0},{1,0},{2,0},{2,1}}
                                                , { {0,0},{0,1},{1,1},{2,1}}
                                                , { {0,1},{1,1},{1,0},{2,1}}
                                                , { {0,1},{1,1},{2,1},{2,0}}
                                                , { {0,1},{1,1},{1,0},{2,0}}
                                                , { {0,0},{1,0},{1,1},{2,1}} };

    //
    int calc(int x, int y, int gubun) {
        int sum = 0;

        if (gubun == 1) {
            for (int i = 0; i < fourbyone.size(); i++) {
                sum += board[x + fourbyone[i].first][y + fourbyone[i].second];
            }
            return sum;
        }
        else if (gubun == 2) {
            for (int i = 0; i < onebyfour.size(); i++) {
                sum += board[x + onebyfour[i].first][y + onebyfour[i].second];
            }
            return sum;
        }
        else if (gubun == 3) {
            for (int i = 0; i < twobytwo.size(); i++) {
                sum += board[x + twobytwo[i].first][y + twobytwo[i].second];
            }
            return sum;
        }
        else if (gubun == 4) {
            int max_sum = -1;
            for (int i = 0; i < threebytwo.size(); i++) {
                int tmp_sum = 0;
                for (int j = 0; j < threebytwo[i].size(); j++) {
                    tmp_sum += board[x + threebytwo[i][j].first][y + threebytwo[i][j].second];
                }
                if (max_sum < tmp_sum) {
                    max_sum = tmp_sum;
                }
            }
            return max_sum;
        }
        else if (gubun == 5) {
            int max_sum = -1;
            for (int i = 0; i < twobythree.size(); i++) {
                int tmp_sum = 0;
                for (int j = 0; j < twobythree[i].size(); j++) {
                    tmp_sum += board[x + twobythree[i][j].first][y + twobythree[i][j].second];
                }
                if (max_sum < tmp_sum) {
                    max_sum = tmp_sum;
                }
            }
            return max_sum;
        }
        return sum;
    }
    int main() {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        int res = -1;
        //경우의 수에 따라서 5번 for문 돌려보기
        // 1. 4*1 -> 1개
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m - 4; j++) {
                int tmp = calc(i, j, 1);
                res = max(tmp, res);
            }
        }

        // 2. 1*4 -> 1개
        for (int i = 0; i <= n - 4; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = calc(i, j, 2);
                res = max(tmp, res);
            }
        }

        // 3. 2*2 -> 1개
        for (int i = 0; i <= n - 2; i++) {
            for (int j = 0; j <= m - 2; j++) {
                int tmp = calc(i, j, 3);
                res = max(tmp, res);
            }
        }

        // 4. 3*2 -> 8개
        for (int i = 0; i <= n - 2; i++) {
            for (int j = 0; j <= m - 3; j++) {
                int tmp = calc(i, j, 4);
                res = max(tmp, res);
                //cout << i << " " << j << " " << tmp << "\n";
            }
        }

        // 5. 2*3 -> 8개
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 2; j++) {
                int tmp = calc(i, j, 5);
                res = max(tmp, res);
            }
        }

        cout << res;
        return 0;
    }
}
