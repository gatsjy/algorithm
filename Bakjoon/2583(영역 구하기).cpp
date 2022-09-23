#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int d;

int a[101][101], visited[101][101];

int yy2, yy1, xx2, xx1;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> m >> n >> k;

	for (int d = 0; d < k; d++) {
		// y1, x1 -> 왼쪽아래
		// y2, x2 -> 오른쪽위
		cin >> yy1 >> xx1 >> yy2 >> xx2;

		for (int i = 0; i < (yy2 - yy1); i++) {
			for (int j = 0; j < (xx2 - xx1); j++) {
				visited[i][j] = 1;
			}
		}
	}

	cout << "1" << endl;
	return 0;
}