#include <bits/stdc++.h>

using namespace std;

namespace _å {
	// �� �ڸ��� ���ϴ� �Լ�
	int digit_sum(int x) {
		int sum = 0;
		while (x > 0) {
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}

	// �� �ڸ��� ���ϴ� �Լ�
	int digit_mul(int x) {
		int sum = 1;
		while (x > 0) {
			sum *= x % 10;
			x /= 10;
		}
		return sum;
	}

	int solution(vector<int> pobi, vector<int> crong) {
		// ������ ������ Ȧ ��, ������ ¦��
		// ���� �������� �� �ڸ����� ���ϰų�, ��� ���� ���� ū ���� ���մϴ�.
		// �ڽ��� ��� �߿��� ���� ū ���� �ºμ��� �����ϴ�.
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