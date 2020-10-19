#include <bits/stdc++.h>

using namespace std;

namespace _39 {
    int main() {
        vector<int> ans;

        int idx1 = 0;
        int idx2 = 0;

        int n1, n2;
        cin >> n1;

        // 1. 첫번째 배열
        vector<int> a(n1);

        for (int i = 0; i < n1; i++) {
            cin >> a[i];
        }

        // 2. 두번째 배열

        cin >> n2;

        vector<int> b(n2);

        for (int i = 0; i < n2; i++) {
            cin >> b[i];
        }

        int ridx = 0;

        while (idx1 < n1 && idx2 < n2) {
            if (a[idx1] < b[idx2]) {
                ans.push_back(a[idx1++]);
            }
            else {
                ans.push_back(b[idx2++]);
            }
            ridx++;
        }

        while (n1 != idx1) {
            ans.push_back(a[idx1++]);
        }

        while (n2 != idx2) {
            ans.push_back(b[idx2++]);
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }

        return 0;
    }
}
