#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace _50{
    int res = -1;
    int main() {
        // ¼¼·Î, °¡·Î, ¶¥¼¼·Î, ¶¥°¡·Î
        int h, w, n, m;
        cin >> h >> w;

        vector<vector<int>> map = vector<vector<int>>(h, vector<int>(w, 0));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        cin >> n >> m;

        for (int i = 0; i < h - n; i++) {
            for (int j = 0; j < w - m; j++) {
                int sum = 0;
                for (int k = i; k < i + n; k++) {
                    for (int l = j; l < j + m; l++) {
                        sum += map[k][l];
                    }
                }
                res = max(res, sum);
            }
        }
        cout << res;
        return 0;
    }
}
