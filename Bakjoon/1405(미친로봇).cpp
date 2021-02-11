#include <vector>
#include <iostream>

using namespace std;

namespace _1405 {
    int n;

    int visit[30][30];
    int x = 15, y = 15; // ������ üũ 
    double per[4];

    // ���ʴ�� ��,��,��,��
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    int cnt = 0;
    double sum = 0;

    double dfs(int x, int y, int depth) {
        if (depth == n) {
            return 1;
        }
        visit[x][y] = 1;
        double res = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            res += per[i] * dfs(nx, ny, depth + 1);
        }
        visit[x][y] = 0;
        return res;
    }

    int main() {

        cin >> n;

        // 2. ��, ��, ��, �� Ȯ�� �ֱ�
        for (int i = 0; i < 4; i++) {
            double input;
            cin >> input;
            per[i] = input / 100;
        }

        // 3. ���� ������ ������� �׹��� ��Ʈ��ŷ �ϱ�
        printf("%0.9lf", dfs(15, 15, 0));
        return 0;
    }
}

