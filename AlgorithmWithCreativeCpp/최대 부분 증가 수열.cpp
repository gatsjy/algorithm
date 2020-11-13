#include <vector>
#include <iostream>

using namespace std;

struct vertex {
    int maxValue;
    int cnt;

    vertex() {}

    vertex(int a, int b) {
        maxValue = a;
        cnt = b;
    }
};

vertex dp[1001];
int a[1001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // ù�� ° ���� �־��ش�.
    dp[1] = vertex(a[1], 1);

    // �ι� ° ������ dp�� ������.
    for (int i = 2; i <= n; i++) {
        if (a[i] > dp[i - 1].maxValue) {
            dp[i].cnt = dp[i - 1].cnt + 1;
            dp[i].maxValue = a[i];
        }
        else {
            dp[i].cnt = dp[i - 1].cnt;
            dp[i].maxValue = dp[i - 1].maxValue;
        }
    }

    cout << dp[n].cnt;
    return 0;
}