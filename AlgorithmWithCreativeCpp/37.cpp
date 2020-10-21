#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace _37 {
    int main() {

        int s, n;
        cin >> s >> n;
        vector<int> a(s);

        while (n--) {
            int target;
            cin >> target;

            int pos = -1;
            // 1. 캐쉬의 히트 여부를 체크
            for (int i = 0; i < s; i++) {
                if (target == a[i]) {
                    pos = -1;
                    break;
                }
            }

            // 2. miss 체크하기
            if (pos == -1) {
                // 미스난 부분을 한칸씩 땡긴다.
                for (int i = s - 1; i > 0; i--) {
                    a[i] = a[i - 1];
                }
            }
            else {
                // 캐치 부분
                for (int i = pos; i > 0; i--) {
                    a[i] = a[i - 1];
                }
            }
            a[0] = target;
        }

        for (int i = 0; i < s; i++) {
            cout << a[i] << " ";
        }
        return 0;
    }
}
