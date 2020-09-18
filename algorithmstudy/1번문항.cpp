#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace socar_ex1 {
	// 1. string (시간값을 int로 변경해주는 메서드)
	int stringToTime(string s) {
		int hour = stoi(s.substr(0, 2));
		int second = stoi(s.substr(3, 4));
		return 60 * hour + second;
	}

	// 2. 
	pair<int, int> splitString(string s) {
		pair<int, int> res;
		int time = stringToTime(s.substr(0, 5));
		string tmp = "";
		for (int i = 6; i < s.size(); i++) {
			tmp += s[i];
		}
		int cnt = stoi(tmp);
		return { time,cnt };
	}

	int solution(vector<string> schedule, string current, int k) {
		int answer = 0;
		vector<pair<int, int>> schedulev;

		// pair<time,cnt>
		for (int i = 0; i < schedule.size(); i++) {
			schedulev.push_back(splitString(schedule[i]));
		}

		// 빵 시간에 맞게 정렬
		sort(schedulev.begin(), schedulev.end());

		int currentTime = stringToTime(current);

		int startIdx = -1;

		for (int i = 0; i < schedulev.size(); i++) {
			if (schedulev[i].first >= currentTime) {
				startIdx = i;
				break;
			}
		}

		if (startIdx == -1) return -1;

		for (int i = startIdx; i < schedulev.size(); i++) {
			if (k > schedulev[i].second) {
				k -= schedulev[i].second;
				continue;
			}
			else if (k <= schedulev[i].second) {
				answer = schedulev[i].first - currentTime;
			}
		}

		return answer;
	}

	int main() {
		// 1. 테스트 케이스1
		/*vector<string> schedule = { "09:05 10","12:20 5","13:25 6", "14:24 5" };
		string current = "12:05";
		int k = 10;*/

		// 2. 테스트 케이스2
		vector<string> schedule = { "12:00 10" };
		string current = "12:00";
		int k = 10;
		solution(schedule, current, 10);

		return 0;
	}
}
