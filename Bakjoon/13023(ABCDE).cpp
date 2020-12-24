#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

namespace _13023 {
    int n, m;
    vector<vector<int>> v;
    vector<int> a;
    int ch[2002];
    int flag = true;

    void dfs(int cur, int level) {
        if (!flag) return;
        if (level == 5) {
            //for (int i = 0; i < 5; i++) {
            //   cout << a[i] << " ";
            //}
            //cout << "\n";
            flag = false;
        }
        else {
            for (int i = 0; i < v[cur].size(); i++) {
                int next = v[cur][i];
                if (ch[next] == 0) {
                    a.push_back(next);
                    ch[next] = 1;
                    dfs(next, level + 1);
                    a.pop_back();
                    ch[next] = 0;
                }
            }
        }
    }

    int main() {
        cin >> n >> m;
        v.resize(n);

        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, 0);
        }

        if (flag) {
            cout << 0;
        }
        else {
            cout << 1;
        }

        return 0;
    }
}
