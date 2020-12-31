#include <bits/stdc++.h>

using namespace std;

namespace _15661 {
    int board[21][21];
    int ch[21];
    int n;
    vector<int> a;
    int res = 2147000000;

    void dfs(int idx, int size) {
        if (a.size() == size) {
            vector<int> partA;
            vector<int> partB;

            int sum_partA = 0;
            int sum_partB = 0;
            for (int i = 0; i < n; i++) {
                if (ch[i] == 0) {
                    partA.push_back(i);
                }
                else {
                    partB.push_back(i);
                }
            }
            for (int i = 0; i < partA.size(); i++) {
                for (int j = i + 1; j < partA.size(); j++) {
                    sum_partA += board[partA[i]][partA[j]] + board[partA[j]][partA[i]];
                }
            }
            for (int i = 0; i < partB.size(); i++) {
                for (int j = i + 1; j < partB.size(); j++) {
                    sum_partB += board[partB[i]][partB[j]] + board[partB[j]][partB[i]];
                }
            }
            res = min(res, abs(sum_partA - sum_partB));
            //for (int i = 0; i < a.size(); i++) {
            //    cout << a[i] << " ";
            //}
            //cout << "\n";
        }
        else {
            for (int i = idx; i < n; i++) {
                if (ch[i] == 0) {
                    a.push_back(i);
                    ch[i] = 1;
                    dfs(i + 1, size);
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
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 1; i < n; i++) {
            memset(ch, 0, sizeof(ch));
            dfs(0, i);
        }

        cout << res;

        return 0;
    }
}
