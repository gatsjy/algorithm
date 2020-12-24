#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

namespace _16926 {
    int n, m, cnt;
    long long board[302][302];

    // 0 : ��, 1 : ��, 2 : ��, 3 : ��
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    // x,y ��ġ, 
    void dfs(int x, int y, int dir, long long next, int gSeq) {
        long long cur = board[x][y];
        board[x][y] = next;
        long long nx = x + dx[dir];
        long long ny = y + dy[dir];
        //if (nx < 0 || ny < 0 || (nx < gSeq || ny < gSeq)) return;
        // 1,1 ���� �����ϸ� ���� ��Ʈ�� �ȸ���.. ����?

        if ((dir == 3 && (x == gSeq && y == gSeq)) || dir >= 4) {
            return;
        };
        // �����δٸ� ������ ���� nx + n - gSeq ���� �̵�����, ���δ� ny + m - gSeq���� �̵�����
        if ((dir == 0)
            && (x == (n - gSeq - 1) && y == gSeq)) {
            nx = x + dx[dir + 1];
            ny = y + dy[dir + 1];
            //cout << nx << " " << ny << "\n";
            dfs(nx, ny, dir + 1, cur, gSeq);
        }
        else if ((dir == 1)
            && (x == (n - gSeq - 1) && y == (m - gSeq - 1))) {
            nx = x + dx[dir + 1];
            ny = y + dy[dir + 1];
            //cout << nx << " " << ny << "\n";
            dfs(nx, ny, dir + 1, cur, gSeq);
        }
        else if ((dir == 2)
            && (x == gSeq && y == (m - gSeq - 1))) {
            nx = x + dx[dir + 1];
            ny = y + dy[dir + 1];
            //cout << nx << " " << ny << "\n";
            dfs(nx, ny, dir + 1, cur, gSeq);
        }
        else {
            //cout << nx << " " << ny << "\n";
            dfs(nx, ny, dir, cur, gSeq);
        }
    }

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        cin >> n >> m >> cnt;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        // ���� ���̽� �� ��ŭ �迭 ȸ����Ű��
        // * ���̽��� �׷��� �Ѵܰ� �Ѵܰ� ��������� ���� ��ġ�� (1,1)�� �����Ѵ�.
        // ** (0,0)���� �����ϸ� �ѹ����� ���� �Ŀ� (0,0)���� ���ƿ´�.
        while (cnt--) {
            // �׸� �� ��ŭ dfs�� ������.
            for (int i = 0; i < min(n, m) / 2; i++) {
                dfs(i, i, 0, board[i][i + 1], i); // ó�� ������ ������ ������ ��
                //cout << "***********************" << "i : " << i << "****************" << "\n";
            }
        }

        // ���� ���� ���
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
}