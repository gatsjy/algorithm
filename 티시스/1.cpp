#include <iostream>

using namespace std;
int n;
int board[21][21];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	// 2021-01-21, ���־�, ���� �ۼ�
	// ** �迭�� ������� �ʰ� Ǫ�� ����� �ְ�����,
	// ** ������ �Ѵ��� �˾ƺ� �� �ִ� �ڵ��� ������������ �޸��� ������ ��뺸�� ���ٰ� �Ǵ�

	// �Է°� ��ȿ�� üũ (20������ �ڿ���)
	if (n <= 20) {
		// 1. �迭�� �ϳ��ϳ� �־��� cnt ���� ����
		int cnt = 1;

		// 2. �迭�� �Ҵ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[j][i] = cnt++;
			}
		}

		// 2. ������ִ� �κ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}