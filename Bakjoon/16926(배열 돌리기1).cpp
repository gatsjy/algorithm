#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, m, cnt;
int board[302][302];

// 0 : ��, 1 : ��, 2 : ��, 3 : ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag = true;
// x,y ��ġ, 
void dfs(int x, int y, int dir, int next, int gSeq) {

    int cur = board[x][y];
    board[x][y] = next;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    // ���� ������ '��'�̰� ����ġ�� ���ƿ� ��� return
    if ((dir == 3 && (x == gSeq && y == gSeq)) || dir >=4) {
        return;
    };

    // �����δٸ� ������ ���� nx + n - gSeq ���� �̵�����, ���δ� ny + m - gSeq���� �̵�����
    // ��, ��, ���� �� ���ǽ����� ���� �� ������, ������ �Ͽ��� ���� �������� ���� ����.
    if (nx > (n - gSeq - 1) || ny > (m - gSeq - 1) || nx < 0 || ny < 0)
    {
        nx = x + dx[dir + 1];
        ny = y + dy[dir + 1];
        dfs(nx, ny, dir + 1, cur, gSeq);
    }
    else {
        dfs(nx, ny, dir, cur, gSeq);
    }
}

int main() {
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
        for (int i = 0; i < n / 2; i++) {
        //for (int i = 0; i <= min(n, m) / 2; i++) {
            dfs(i, i, 0, board[i][i+1], i); // ó�� ������ ������ ������ ��
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