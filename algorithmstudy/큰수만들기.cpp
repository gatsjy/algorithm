#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	// ���� ��ġ�� ǥ���� idx
	int cur = 0;
	// ������ ����
	int n = number.size() - k;
	for (int i = 0; i < n; i++) {
		int max_idx = cur;
		for (int j = cur + 1; j < number.size(); j++) {
			if (number.size() - j < n - answer.size()) break;
			// idx �� 0 1 2 3 4 5 6 �̸�
			// �� �ڿ� �� �� �ִ� ���� �������
			// ���ʷ� 6 5 4 3 2 1 0 �� ���̴�
			// ex) 34** -> ��ǥ ù��° �ڸ��� �ڿ� �Ѱ�, ��ǥ �ι�° �ڸ��� �ڿ� 0��
			// ���� �ּ����� ������ ������ ������ ���ϴ� ���� ������ �տ��� �ִ밪�� �����ش�.
			if (number[j] > number[max_idx] && number.size() - j >= n - answer.size()) {
				max_idx = j;
			}
		}
		answer.push_back(number[max_idx]);
		cur = ++max_idx;
	}
	return answer;
}