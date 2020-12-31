#include <bits/stdc++.h>

using namespace std;

namespace _18290 {
    int dy[4] = { 0,0,1,-1 };
    int dx[4] = { 1,-1,0,0 };
    int n, m, k;

    int board[11][11];
    vector<int> ch;
    vector<int> v;

    int res = 0;

    // 1. �̰ɷ� ���ϸ� �ð��ʰ��� ����.
    //bool isDouble(vector<pair<int, int>> &a) {
    //   map<pair<int, int>, int> doublech;
    //   for (int i = 0; i < a.size(); i++) {
    //      doublech[{a[i].first, a[i].second}]++;
    //   }
    //   map<pair<int, int>, int>::iterator iter;
    //   for (iter = doublech.begin(); iter != doublech.end(); iter++) {
    //      if (iter->second > 1) return true;
    //   }
    //   return false;
    //}

    // 2. �̰͵� �ð� �ʰ��� ����...
    // �ƾ� �����Ҷ� ������ ������ �� ��?
    bool isDouble(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                if (i == j) continue;
                int x = a[i] / m;
                int y = a[i] % m;
                int x2 = a[j] / m;
                int y2 = a[j] % m;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (x2 == nx && y2 == ny) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // ������ �ƴ϶� 1������ �غ��� -> �̰͵� ���ο� ������
    void solution(int idx) {
        if (v.size() == k) {
            if (isDouble(v)) return;
            int sum = 0;
            for (int i = 0; i < v.size(); i++) {
                sum += board[v[i] / m][v[i] % m];
            }
            res = max(res, sum);
            return;
        }
        for (int i = idx; i < n * m; i++) {
            if (ch[i] == 0) {
                v.push_back(i);
                ch[i] = 1;
                solution(i + 1);
                ch[i] = 0;
                v.pop_back();
            }
        }
    }

    int main() {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        cin >> n >> m >> k;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        ch.resize(n * m + 1);
        solution(0);

        cout << res;
        return 0;
    }
}
