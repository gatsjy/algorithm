#include <bits/stdc++.h>

using namespace std;

namespace _12{
	int main() {
		// ���� �������� ��� �ذ��ؾ� �ұ�?
		// 1. ���� ���� ���� �ڸ����� Ȯ���Ѵ�.
		int n, cnt = 0;
		cin >> n;
		int digitCnt = to_string(n).size();

		// 2. �ڸ����� ���������� ���
		for (int i = 1; i < digitCnt; i++) {
			cnt += i * (9 * pow(10, i - 1));
		}

		// 3. �ش� �ڸ����� ���� ���
		cnt += digitCnt * (n - pow(10, digitCnt - 1) + 1);
		cout << cnt;

		return 0;
	}
}