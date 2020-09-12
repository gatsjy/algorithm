#include <stdio.h>

int main() {
    long long dp[101] = { 0,1,1,1,2,2,3,4,5,7,9, };

    for (int i = 11; i <= 100; i++) {
        dp[i] = dp[i - 5] + dp[i - 1];
    }

    int cnt;
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

}
​