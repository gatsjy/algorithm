#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;


// 티켓 구매자 명단
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
// 1. 접속시도를 하면 request로고가 남고 접속 후 1분 이내 접속을 종료하면 leave 로고가 남는다. (leave가 나오는 순간 티켓팅은 x)
// 2. 결과는 set에 담아야 할듯? -> 중복을 피하기 위해서
// 3. request가 들어왔을때 해당 사항의 이전의 값과 같지 않다면?
// 4. 경계값 (10시)때문에 시간도 계산 해야함.
// 5. 완료자 명단을 따로 넣어서 체크해야함 -> 산사람이 다시 등장할 수 있음
vector<string> solution(int totalTicket, vector<string> logs) {
	vector<string> res;

	// critical Section programmed by stack
	// <"이름", "접근시간">
	stack<pair<string, int>> st;

	for (int i = 0; i < logs.size(); i++) {
		vector<string> ss = StringSplit(logs[i], ' ');

		// 서버 접근 가능한지 체크
		// 서버가 비어있는 경우 
		if (st.empty()) {
			// request 요청 일 경우 
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