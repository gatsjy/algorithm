#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 1. split 함수
vector<string> splitString(string str, char delimeter) {
    vector<string> res;
    string tmp = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == delimeter) {
            res.push_back(tmp);
            tmp = "";
        }
        else if (str[i] != delimeter) {
            tmp += str[i];
        }
    }
    res.push_back(tmp);
    return res;
}

// 2. 처리시간 구하는 함수
int calProcessTime(string s) {
    return stof(s.substr(0, s.size() - 1)) * 1000;
}

// 3. 시작시간 구하는 함수 
int calEndTime(string s) {
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stof(s.substr(6)) * 1000;
    return hh * 60 * 60 * 1000 + mm * 1000 * 60 + ss;
}

int solution(vector<string> lines) {
    int answer = 0;

    // <시작시간, 종료시간>
    vector<pair<int, int>> process;
    for (int i = 0; i < lines.size(); i++) {
        vector<string> ss = splitString(lines[i], ' ');
        // 처리시간 체크 함수
        int processTime = calProcessTime(ss[2]);
        // 끝나는시간 체크 함수
        int endTime = calEndTime(ss[1]);
        // 시작 시간 계산
        int startTime = endTime - processTime + 1;
        //cout << startTime << " ~ " << endTime << endl;
        process.push_back({ startTime, endTime });
    }

    // 이중 포문으로 시간 계산
    for (int i = 0; i < process.size(); i++) {
        int checkStartTime = process[i].second;
        int checkEndTime = checkStartTime + 999;
        int cnt = 0;
        for (int j = 0; j < process.size(); j++) {
            // 1. checkStart에 걸릴 때
            // 2, checnEnd에 걸릴 때
            if ((process[j].first <= checkStartTime && process[j].second >= checkStartTime) ||
                (process[j].first <= checkEndTime && process[j].second >= checkEndTime)) {
                cnt++;
            }
        }
        answer = max(cnt, answer);
    }
    return answer+1;
}

int main() {
    //vector<string> lines = {
    //    "2016-09-15 20:59:57.421 0.351s",
    //    "2016-09-15 20:59:58.233 1.181s",
    //    "2016-09-15 20:59:58.299 0.8s",
    //    "2016-09-15 20:59:58.688 1.041s",
    //    "2016-09-15 20:59:59.591 1.412s",
    //    "2016-09-15 21:00:00.464 1.466s",
    //    "2016-09-15 21:00:00.741 1.581s",
    //    "2016-09-15 21:00:00.748 2.31s",
    //    "2016-09-15 21:00:00.966 0.381s",
    //    "2016-09-15 21:00:02.066 2.62s"
    //};

    vector<string> lines = {
        "2016-09-15 01:00:04.002 2.0s", 
        "2016-09-15 01:00:07.000 2s"
    };

    solution(lines);
    return 0;
}