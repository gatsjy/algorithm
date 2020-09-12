#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
vector<char> a; // 기본 char셋
vector<char> v; // dfs char셋
vector<pair<int, multimap<int, string,greater<int>>>> mm(21); // 결과를 체크할 맵
int IsCount(string chk, const vector<string>& target) {
    int cnt = 0;
    for (int i = 0; i < target.size(); i++) {
        int chkcnt = 0;
        if (chk.size() <= target[i].size()) {
            for (int j = 0; j < chk.size(); j++) {
                for (int k = 0; k < target[i].size(); k++) {
                    if (chk[j] == target[i][k]) {
                        chkcnt++;
                        break;
                    }
                }
            }
            if (chkcnt == chk.size()) {
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(int idx, int size, const vector<string>& orders) {
    if (v.size() == size) {
        string chk = "";
        for (int i = 0; i < size; i++) {
            chk += v[i];
        }
        if (IsCount(chk, orders) > 1) {
            mm[IsCount(chk, orders)].second.insert({chk.size(), chk});
        }
        return;
    }
    else {
        for (int i = idx; i < a.size(); i++) {
            v.push_back(a[i]);
            dfs(i+1,size, orders);
            v.pop_back();
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 1. 어떤것을 조합으로 만들지 찾는다.
    int cc[26] = {};
    for (int i = 0; i< orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            cc[orders[i][j] - 'A']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (cc[i] > 1) {
            a.push_back(i + 'A');
        }
    }

    // 3. 조합에 따라서 구한다.
    for (int i = 0; i < course.size(); i++) {
        v = vector<char>();
        dfs(0, course[i], orders);
    }

    for (int i = 21; i >= 2; i--) {
        if (mm[i].second.size() > 1) {
            multimap<int, string>::iterator iter;
            for (iter = mm[i].second.begin(); iter != mm[i].second.lower_bound(4); iter++) {
                cout << "1" << endl;
            }
        }
    }

    return answer;
}

int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    //vector<string> orders = { "XYZ", "XWY", "WXA" };
    vector<int> course = {2,3,4};
    solution(orders, course);

    return 0;
}