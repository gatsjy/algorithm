#include <bits/stdc++.h>

using namespace std;

namespace _1��_��_������ {
	int n, k;
	int result;

	int main() {
		cin >> n >> k;
		while (1) {
			int target = (n / k) * k; // �ֳ��ϸ� -1 �� ���ִµ� �ش� �ϴ� ������ �����ؾ��Ѵ�.
			result += (n - target);
			// N�� K���� ������ �ݺ��� Ż��
			if (n < k) break;
			result++;
			n /= k;
		}
		result += (n - 1);
		cout << result;
		return 0;
	}
}