#include <bits/stdc++.h>

using namespace std;

int n; // n�� 2�̻� 100������ ����
int visited[101][101], a[101][101];
int max_height = -2147000000;
int input;
int cnt; // ���� ����� �ʴ� �ִ� ����
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			a[i][j] = input;
			max_height = max(max_height, input);
		}
	}

	for (int i = 1; i < max_height; i++) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i >= a[j][k]) visited[j][k] = 1;
			}
		}
	}


	return 0;
}