#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<string> answer;
vector<string> ch;
map<string, vector<string>> m;

bool isFind(vector<string>& v, string s) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s) return true;
    }
    return false;
}

void dfs(string cur, vector<vector<string>> &tickets) {
    answer.push_back(cur);
    for (int i = 0; i < m[cur].size(); i++) {
        if (!isFind(ch, m[cur][i])) {
            ch.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets);
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back(tickets[i][1]);
    }
    ch.push_back("ICN");
    dfs("ICN", tickets);

    return answer;
}

int main() {
    vector<vector<string>> tickets = { { "ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"}};
    
    solution(tickets);

    return 0;
}