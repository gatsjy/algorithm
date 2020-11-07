#include <bits/stdc++.h>

using namespace std;

namespace _책 {
	// 각 자리수 더하는 함수
	int digit_sum(int x) {
		int sum = 0;
		while (x > 0) {
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}

	// 각 자리수 곱하는 함수
	int digit_mul(int x) {
		int sum = 1;
		while (x > 0) {
			sum *= x % 10;
			x /= 10;
		}
		return sum;
	}

	int solution(vector<int> pobi, vector<int> crong) {
		// 페이지 왼쪽은 홀 수, 우측은 짝수
		// 왼쪽 페이지의 각 자리수를 더하거나, 모두 곱해 가장 큰 수를 구합니다.
		// 자신의 기록 중에서 가장 큰 값을 승부수로 던집니다.
		int pobimax = max(max(digit_sum(pobi[0]), digit_mul(pobi[0])), max(digit_sum(pobi[1]), digit_mul(pobi[1])));
		int crongmax = max(max(digit_sum(crong[0]), digit_mul(crong[0])), max(digit_sum(crong[1]), digit_mul(crong[1])));

		if (pobimax == crongmax) {
			return 0;
		}
		else if (pobimax > crongmax) {
			return 1;
		}
		else if (pobimax < crongmax) {
			return 2;
		}
		else {
			return -1;
		}
	}
	int main() {
		/*vector<int> pobi = {97,98};
		vector<int> crong = {197,198};*/
		vector<int> pobi = { 131,132 };
		vector<int> crong = { 211,212 };
		solution(pobi, crong);
		return 0;
	}
}