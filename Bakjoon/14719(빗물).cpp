#include<bits/stdc++.h>

using namespace std;

namespace _14719 {
	int h, w;

	int block[501];
	int main(void) {
		cin >> h >> w;
		for (int i = 0; i < w; i++) {
			cin >> block[i];
		}
		int sum = 0;
		int left = 0;
		int right = w - 1;
		int left_max = block[left];
		int right_max = block[right];

		// ���� ū ������ �߰������� ã�� ���� Ž��
		while (left < right) {
			left_max = max(left_max, block[left]);
			right_max = max(right_max, block[right]);
			if (left_max <= right_max) {
				// �������� ũ�ٸ� ���ʿ��� ���� ä���������Ұ��̴�.(�������� �������� �ؾ��ϱ� ������..)
				sum += left_max - block[left];
				left++;
			}
			else {
				sum += right_max - block[right];
				right--;
			}
		}
		cout << sum;
		return 0;
	}
}
