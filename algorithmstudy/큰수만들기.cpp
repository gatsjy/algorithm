#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	// 현재 위치를 표현할 idx
	int cur = 0;
	// 정답의 길이
	int n = number.size() - k;
	for (int i = 0; i < n; i++) {
		int max_idx = cur;
		for (int j = cur + 1; j < number.size(); j++) {
			if (number.size() - j < n - answer.size()) break;
			// idx 가 0 1 2 3 4 5 6 이면
			// 그 뒤에 들어갈 수 있는 수의 사이즈는
			// 차례로 6 5 4 3 2 1 0 일 것이다
			// ex) 34** -> 별표 첫번째 자리는 뒤에 한개, 별표 두번째 자리는 뒤에 0개
			// 가장 최소한의 값까지 포문을 돌리고 원하는 값이 없으면 앞에서 최대값을 더해준다.
			if (number[j] > number[max_idx] && number.size() - j >= n - answer.size()) {
				max_idx = j;
			}
		}
		answer.push_back(number[max_idx]);
		cur = ++max_idx;
	}
	return answer;
}