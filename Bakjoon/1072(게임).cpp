#include <bits/stdc++.h>

using namespace std;

// �̺а˻��� ����ϴ������� �����ϱ�?
// 1~100�� �˻����Ѵٰ� �����ϸ� Ư�� ���� ã�� �˰����� 
// �ϳ��� �˻��ϸ� n / ������ �ݾ� �پ���� log2n
long long x, y;
long long res = 2147000000;
int main() {
	cin >> x >> y;
	//cout << (y / x) * 100 << "\n";
	//for (int i = 0; i < 10; i++) {
	//	y++;
	//	x++;
	//	cout << (y / x) * 100 << "\n";
	//}
	long long lt = 1;
	long long rt = 1000000000;

	int wrate = (int)(((float)y / (float)x) * 100)+1;

	if (wrate >= 100) {
		res = 1;
	}else{
		// �̺� �˻� ����..
		while (lt <= rt) {
			long long mid = (lt + rt) / 2;
			// twrate == temp win rate
			int twrate = (int)((((float)y + mid) / ((float)x + mid)) * 100);
			if (twrate >= wrate) {
				rt = mid - 1;
				res = min(mid, res);
			}
			else {
				lt = mid + 1;
			}
		}
	}
	
	cout << res;
	return 0;
}