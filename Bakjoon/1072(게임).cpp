#include <bits/stdc++.h>

using namespace std;
namespace _1072 {
	// �̺а˻��� ����ϴ������� �����ϱ�?
// 1~100�� �˻����Ѵٰ� �����ϸ� Ư�� ���� ã�� �˰����� 
// �ϳ��� �˻��ϸ� n / ������ �ݾ� �پ���� log2n
	long long x, y;
	long long res = 2147000000;
	int main() {
		cin >> x >> y;
		long long lt = 1;
		long long rt = 2000000001;

		int wrate = y * 100 / x;

		if (wrate >= 99) {
			cout << -1;
		}
		else {
			// �̺� �˻� ����..
			while (lt <= rt) {
				long long mid = (lt + rt) / 2;
				// twrate == temp win rate
				int twrate = (y + mid) * 100 / (x + mid);
				if (twrate > wrate) {
					rt = mid - 1;
				}
				else {
					lt = mid + 1;
				}
			}
			cout << lt;
		}
		return 0;
	}
}