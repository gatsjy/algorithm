#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace _51 {
    int map[701][701];
    int dp[701][701];
    int res = -1;
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // ¼¼·Î, °¡·Î, ¶¥¼¼·Î, ¶¥°¡·Î
        int h, w, n, m;
        scanf_s("%d %d", &h, &w);

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                scanf_s("%d", &map[i][j]);
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + map[i][j];
            }
        }
        scanf_s("%d %d", &n, &m);
        for (int i = n; i <= h; i++) {
            for (int j = m; j <= w; j++) {
                int tmp = dp[i][j] - dp[i][j - m] - dp[i - n][j] + dp[i - n][j - m];
                if (tmp > res) res = tmp;
            }
        }
        cout << res;
        return 0;
    }
}
