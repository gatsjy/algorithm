#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool bfs(vector<string> drum, vector<vector<bool>> ch, int startX, int startY) {
	queue<pair<int, int>> q;
	q.push({startX, startY});
	ch[startX][startY] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int xx = cur.first;
		int yy = cur.second;
		// # 은 아래로 한칸을 의미합니다. (-1,0)
		if (drum[cur.first][cur.second] == '#') {
			xx += 1;
		}
		// * 은 처음만나면 아래로 한칸, 한번더 만나면 거기서 멈춰 버립니다. (-1,0)
		else if (drum[cur.first][cur.second] == '*') {
			xx += 1;
		}
		// > 은 오른쪽으로 움직이는 것을 의미합니다. (0,1)
		else if (drum[cur.first][cur.second] == '>') {
			yy += 1;
		}
		// < 은 왼쪽으로 움직이는 것을 의미합니다. (0,-1)
		else if (drum[cur.first][cur.second] == '<') {
			yy -= 1;
		}

		// 아 근데 여기서 어떻게 잡아낼 수 있을까? 이것이 도착했다는 것을?
		// 그리고 또한 한번 사용한 기회 (*)을 어떻게 체크해 낼 수 있을까?
		// 그리고 첫번째 줄에서 drum.size() 만큼 for문을 어떻게 돌려 낼 수 있을까?
		// 위에서 제기된 세가지 의문을 풀어야만 이 문제를 해결 할 수 있다.
		// 아니 왜 나는 자꾸 BFS에 집착하는 거지??
		if (xx < 0 || yy < 0 || xx >= drum.size() || yy >= drum.size()) continue;
		if (ch[xx][yy]) continue;
		q.push({ xx,yy });
		ch[xx][yy] = true;
	}

	return true;
}

int solution(vector<string> drum) {

	int answer = 0;
	vector<vector<bool>> ch = vector<vector<bool>>(drum.size(), vector<bool>(drum.size(), 0));
	for (int i = 0; i < drum.size(); i++) {
		if (bfs(drum, ch, 0, i)) {
			answer++;
		}
	}

	return answer;
}

int main() {
	vector<string> drum = { "######", ">#*###", "####*#","#<#>>#",">#*#*<", "######" };
	solution(drum);

	return 0;
}