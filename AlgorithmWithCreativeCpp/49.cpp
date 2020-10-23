#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace _49 {
    int main() {
        int n;
        cin >> n;

        vector<int> front(n);
        for (int i = 0; i < n; i++) {
            cin >> front[i];
        }
        vector<int> side(n);
        for (int i = 0; i < n; i++) {
            cin >> side[i];
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += min(front[i], side[j]);
            }
        }
        cout << sum;
        return 0;
    }
}