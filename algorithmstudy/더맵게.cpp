#include <iostream>
#include <queue>

using namespace std;
int solution(vector<int> scovile, int K) {

	int answer = 0;

	// priority_queue �����ϴ� ��� ����صα� (���ı��� �ؼ� �ֱ�)
	priority_queue<int, vector<int>, greater<int>> pq(scovile.begin(), scovile.end());

	// ���� ���� (��������)
	while (pq.top() < K) {
		if (pq.size() == 1) return -1;
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		// ���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
		pq.push(first + 2 * second);
		answer++;
	}

	return answer;
}