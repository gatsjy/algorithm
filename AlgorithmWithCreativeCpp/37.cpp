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
            // 1. ĳ���� ��Ʈ ���θ� üũ
            for (int i = 0; i < s; i++) {
                if (target == a[i]) {
                    pos = -1;
                    break;
                }
            }

            // 2. miss üũ�ϱ�
            if (pos == -1) {
                // �̽��� �κ��� ��ĭ�� �����.
                for (int i = s - 1; i > 0; i--) {
                    a[i] = a[i - 1];
                }
            }
            else {
                // ĳġ �κ�
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
