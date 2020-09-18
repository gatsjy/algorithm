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
		// # �� �Ʒ��� ��ĭ�� �ǹ��մϴ�. (-1,0)
		if (drum[cur.first][cur.second] == '#') {
			xx += 1;
		}
		// * �� ó�������� �Ʒ��� ��ĭ, �ѹ��� ������ �ű⼭ ���� �����ϴ�. (-1,0)
		else if (drum[cur.first][cur.second] == '*') {
			xx += 1;
		}
		// > �� ���������� �����̴� ���� �ǹ��մϴ�. (0,1)
		else if (drum[cur.first][cur.second] == '>') {
			yy += 1;
		}
		// < �� �������� �����̴� ���� �ǹ��մϴ�. (0,-1)
		else if (drum[cur.first][cur.second] == '<') {
			yy -= 1;
		}

		// �� �ٵ� ���⼭ ��� ��Ƴ� �� ������? �̰��� �����ߴٴ� ����?
		// �׸��� ���� �ѹ� ����� ��ȸ (*)�� ��� üũ�� �� �� ������?
		// �׸��� ù��° �ٿ��� drum.size() ��ŭ for���� ��� ���� �� �� ������?
		// ������ ����� ������ �ǹ��� Ǯ��߸� �� ������ �ذ� �� �� �ִ�.
		// �ƴ� �� ���� �ڲ� BFS�� �����ϴ� ����??
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