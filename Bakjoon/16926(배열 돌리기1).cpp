#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, m, cnt;
int board[302][302];
int nboard[302][302];
int ch[302][302];

int main() {
    cin >> n >> m >> cnt;

    // 1. ch �迭 �Ҵ�
    for (int i = 0; i < 302; i++) {
        for (int j = 0; j < 302; j++) {
            ch[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 1. �ܰ迡 ���� �����ڸ��� ���
    // 2. ch�迭�� ���� ������� ���� �������� �����ڸ��� �� �� �ִ�.
    for (int i = 0; i <= n / 2; i++) {
        if (i == 0) {
            for (int k = i; k < n; k++) {
                for (int h = i; h < m; h++) {
                    ch[k][h] = i;
                }
            }
        }
        else {
            for (int k = i; k <= n - (2 * i); k++) {
                for (int h = i; h <= m - (2 * i); h++) {
                    ch[k][h] = i;
                }
            }
        }
    }

    // ���� ���̽� �� ��ŭ �迭 ȸ����Ű��
    while (cnt--) {
        for (int i = 0; i <= n / 2; i++) {
            
            int counter = i;

            if (i == 0) {
                // ���� i,i -> i+n-1, i+m-1
                // 1. ��
                for (int k = i; k < n; k++) {
                    if (counter == i) {
                        // ������ i,i
                        nboard[i+k+1][i] = board[i+k][i];
                    }
                }
                // 2. ��
                for (int h = i; h < m; h++) {
                    if (counter == i) {
                        // ������ i+n,i
                        nboard[i + n][i + h+1] = board[i + n][i + h];
                    }
                }
                // 3. ��
                for (int k = i; k < n; k++) {
                    if (counter == i) {
                        // ������ i+n,i+m
                        nboard[i + n - k-1][i + m] = board[i + n - k][i + m];
                    }
                }
                // 4. ��
                for (int h = i; h < m; h++) {
                    if (counter == i) {
                        // ������ i, i+m
                        nboard[i][i + m - h-1] = board[i][i + m - h];
                    }
                }
            }
            else {
                // ���� i,i -> n - (2 * i) , m - (2 * i)
                // 1. ��
                for (int k = i; k < n; k++) {
                    if (counter == i) {
                        // ������ i,i
                        nboard[i + k + 1][i] = board[i + k][i];
                    }
                }
                // 2. ��
                for (int h = i; h < m; h++) {
                    if (counter == i) {
                        // ������ i+n - (2 * i),i
                        nboard[i + n - (2 * i)][i + h + 1] = board[i + n - (2 * i)][i + h];
                    }
                }
                // 3. ��
                for (int k = i; k < n; k++) {
                    if (counter == i) {
                        // ������ i+n - (2 * i),i+m - (2 * i)
                        nboard[i + n - (2 * i) - k - 1][i + m - (2 * i)] = board[i + n - (2 * i) - k][i + m - (2 * i)];
                    }
                }
                // 4. ��
                for (int h = i; h < m; h++) {
                    if (counter == i) {
                        // ������ i, i+m - (2 * i)
                        nboard[i][i + m - (2 * i) - h - 1] = board[i][i + m - (2 * i) - h];
                    }
                }
            }
        }
        // �̵��� �迭 �Ҵ�
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j++) {
                board[i][j] = nboard[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}