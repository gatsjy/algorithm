#include <iostream>

using namespace std;

int a[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;

    // 이중 포문으로 dp를 계산한다.
    for (int i = 1; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (tmp < dp[j]) {
                    tmp = dp[j];
                }
            }
        }
        dp[i] = tmp + 1;
    }

    int res = -1;
    for (int i = 0; i < n; i++) {
        if (res < dp[i]) res = dp[i];
    }

    cout << res;
    return 0;
}