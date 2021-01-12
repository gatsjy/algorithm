#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int ch[1001][1001];

int A, B, C;
int sum = 0;

// ���� ������, ���� ū��
queue<pair<int, int>> q;

int main() {
    cin >> A >> B >> C;
    sum = A + B + C;
    if (sum % 3 == 0) {
        int fst_min = min(min(A, B), C);
        int fst_max = max(max(A, B), C);
        q.push({ fst_min,fst_max });
        ch[fst_min][fst_max] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int z = sum - x - y;
            if (x == y && y == z) {
                cout << 1;
                return 0;
            }
            // ����ϴ� ����� ��?
            // x,y / x,z / y,z
            int dx[3] = { x,x,y };
            int dy[3] = { y,z,z };
            for (int i = 0; i < 3; i++) {
                int xx = dx[i];
                int yy = dy[i];
                if (xx > yy)
                {
                    xx -= yy;
                    yy *= 2;
                }
                else if (xx < yy)
                {
                    yy -= xx;
                    xx *= 2;
                }
                else // ���� ������ �׳� �Ѿ�� ������? �ֳ��ϸ� �� ��� ���ϸ� ����� �����ϸ� 0�� �Ǳ� �����̴�.
                {
                    continue;
                }
                int zz = sum - xx - yy;
                int new_min = min(min(xx, yy), zz);
                int new_max = max(max(xx, yy), zz);
                if (ch[new_min][new_max] == 0) {
                    q.push({ new_min, new_max });
                    ch[new_min][new_max] = 1;
                    //cout << new_min << " " << new_max << " " << sum - new_min - new_max << "\n";
                }
            }
        }
    }

    cout << 0;

    return 0;
}