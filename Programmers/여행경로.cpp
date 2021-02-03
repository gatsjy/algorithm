//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//vector<string> answer;
//vector<string> ch;
//unordered_map<string, vector<string>> m;
//
//
//vector<string> solution(vector<vector<string>> tickets) {
//    vector<string> answer;
//    unordered_map<string, vector<string>> m;
//    for (int i = 0; i < tickets.size(); i++) {
//        m[tickets[i][0]].push_back(tickets[i][1]);
//    }
//
//    vector<string> s = vector<string>{ "ICN" }; // 벡터가 stack의 역할을 해준다.
//
//    while (!s.empty()) {
//        string cur = s.back();
//        if (m.find(cur) == m.end() || m[cur].size() == 0) {
//            answer.push_back(cur);
//            s.pop_back();
//        }
//        else {
//            s.push_back(m[cur].back());
//            m[cur].pop_back();
//        }
//    }
//    reverse(answer.begin(), answer.end());
//    return answer;
//}
//
//int main() {
//    vector<vector<string>> tickets = { { "ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"}};
//    vector<vector<string>> tickets2 = { {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };
//    
//    solution(tickets2);
//
//    return 0;
//}