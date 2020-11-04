#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

namespace _2 {
	int moneys[9] = { 50000,10000,5000,1000,500,100,50,10,1 };

	vector<int> solution(int n) {

		vector<int> answer(9);

		for (int i = 0; i < 9; i++) {
			if (n >= moneys[i]) {
				answer[i] += n / moneys[i];
				n = n - (n / moneys[i]) * moneys[i];
			}
		}

		return answer;
	}

	int main() {

		int money = 15000;
		solution(money);
	}
}