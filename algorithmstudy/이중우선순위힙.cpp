#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            string tmp = operations[i].substr(2, string::npos);
            int input = stoi(tmp);
            dq.push_back(input);
            sort(dq.begin(), dq.end());
        }
        else if (operations[i][0] == 'D') {
            // 최소값을 뺍니다.
            if (dq.empty()) continue;
            if (operations[i][2] == '-') {
                dq.pop_front();
            }
            // 최대값을 뺍니다.
            else if (operations[i][2] == '1') {
                dq.pop_back();
            }
        }
    }

    if (dq.empty()) {
        return { 0,0 };
    }

    answer.push_back(dq.back());
    answer.push_back(dq.front());
    return answer;

}