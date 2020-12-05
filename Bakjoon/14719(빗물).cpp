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

		// 가장 큰 길이의 중간지점을 찾기 위한 탐색
		while (left < right) {
			left_max = max(left_max, block[left]);
			right_max = max(right_max, block[right]);
			if (left_max <= right_max) {
				// 오른쪽이 크다면 왼쪽에서 부터 채워나가야할것이다.(낮은것을 기준으로 해야하기 때문에..)
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
