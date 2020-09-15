#include <iostream>
#include <queue>

using namespace std;
int solution(vector<int> scovile, int K) {

	int answer = 0;

	// priority_queue 생성하는 방법 기억해두기 (정렬까지 해서 넣기)
	priority_queue<int, vector<int>, greater<int>> pq(scovile.begin(), scovile.end());

	// 가장 위에 (내림차순)
	while (pq.top() < K) {
		if (pq.size() == 1) return -1;
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
		pq.push(first + 2 * second);
		answer++;
	}

	return answer;
}