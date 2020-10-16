#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;


// Ƽ�� ������ ���
set<string> answer;

vector<string> StringSplit(string s, char gubun) {
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == gubun) {
			res.push_back(tmp);
			tmp = "";
		}
		else if (s[i] != gubun) {
			tmp += s[i];
		}
	}
	res.push_back(tmp);
	return res;
}

int TimeCalculate(string input) {
	vector<string> time = StringSplit(input, ':');
	return stoi(time[0]) * 3600 + stoi(time[1]) * 60 + stoi(time[2]);
}
// 1. ���ӽõ��� �ϸ� request�ΰ� ���� ���� �� 1�� �̳� ������ �����ϸ� leave �ΰ� ���´�. (leave�� ������ ���� Ƽ������ x)
// 2. ����� set�� ��ƾ� �ҵ�? -> �ߺ��� ���ϱ� ���ؼ�
// 3. request�� �������� �ش� ������ ������ ���� ���� �ʴٸ�?
// 4. ��谪 (10��)������ �ð��� ��� �ؾ���.
// 5. �Ϸ��� ����� ���� �־ üũ�ؾ��� -> ������ �ٽ� ������ �� ����
vector<string> solution(int totalTicket, vector<string> logs) {
	vector<string> res;

	// critical Section programmed by stack
	// <"�̸�", "���ٽð�">
	stack<pair<string, int>> st;

	for (int i = 0; i < logs.size(); i++) {
		vector<string> ss = StringSplit(logs[i], ' ');

		// ���� ���� �������� üũ
		// ������ ����ִ� ��� 
		if (st.empty()) {
			// request ��û �� ��� 
			if (ss[1][0] == 'r') {
				st.push({ ss[0], TimeCalculate(ss[2])});
			}
		}
		else if (!st.empty()) {
			auto cur = st.top();
			int time = TimeCalculate(ss[2]);
			int compareTime = time - cur.second;
			if (ss[1][0] == 'l') {
				if (cur.first == ss[0]) {
					if (compareTime >= 60) {
						if (answer.find(ss[0]) == answer.end()) {
							answer.insert(ss[0]);
							totalTicket--;
						}
					}
				}
			}
			else if (ss[1][0] == 'r') {
				if (compareTime >= 60) {
					if (answer.find(ss[0]) == answer.end()) {
						answer.insert(cur.first);
						totalTicket--;
					}
				}
			}
			st.pop();
		}
	}

	set<string>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++) {
		res.push_back(*iter);
	}

	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v = { "woni request 09:12:29"
					   ,"brown request 09:23:11"
					   ,"brown leave 09:23:44"
					   ,"jason request 09:33:51"
					   ,"jun request 09:33:56"
					   ,"cu request 09:34:02" };

	int totalTicket = 2000;

	solution(totalTicket, v);

	return 0;

}