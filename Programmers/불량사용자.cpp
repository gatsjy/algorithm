#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

namespace _불량사용자 {
    vector<pair<string, vector<string>>> list;

    // 금지된 아이디인지 확인 하는 메서드
    bool isBanned(string banned, string target) {
        if (banned.size() != target.size()) {
            return false;
        }
        else {
            for (int i = 0; i < banned.size(); i++) {
                if (banned[i] == '*') continue;
                if (banned[i] != target[i]) return false;
            }
        }
        return true;
    }

    // ch[8]인거 봐서는 브루트포스가 맞을듯..
    string ch[8];

    // 해당 배열에 중복이 있는지 확인 -> 중복이 있으면 탈락
    bool isDouble() {
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (ch[i] == ch[j]) return true;
            }
        }
        return false;
    }

    // set을 이용해서 원하는 값들이 중복인지 체크
    set<string> resstring;

    // 부르트 포스로 모든 경우의 수 탐색
    void dfs(int level) {
        if (level == list.size()) {
            if (!isDouble()) {
                vector<string> tmp;
                for (int i = 0; i < list.size(); i++) {
                    //cout << ch[i] << " ";
                    tmp.push_back(ch[i]);
                }
                sort(tmp.begin(), tmp.end());
                string input = "";
                for (int i = 0; i < tmp.size(); i++) {
                    input += tmp[i];
                }
                resstring.insert(input);
                //cout << "\n";
            }
        }
        else {
            for (int i = 0; i < list[level].second.size(); i++) {
                if (ch[level] == "-1") {
                    ch[level] = list[level].second[i];
                    dfs(level + 1);
                    ch[level] = "-1";
                }
            }
        }
    }


    int solution(vector<string> user_id, vector<string> banned_id) {
        int answer = 0;

        // user_id 가 banned_id에 속해있는지 판단하기
        for (int i = 0; i < banned_id.size(); i++) {
            vector<string> tmp;
            for (int j = 0; j < user_id.size(); j++) {
                if (isBanned(banned_id[i], user_id[j])) {
                    tmp.push_back(user_id[j]);
                }
            }
            list.push_back({ banned_id[i], tmp });
        }

        // ch배열 -1로 초기화
        for (int i = 0; i < 8; i++) {
            ch[i] = "-1";
        }

        // 일단 dfs로 무조건 다 돌려보고 string 값을 만들어보자
        dfs(0);

        return resstring.size();
    }

    int main() {
        vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
        //vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "abcdeg", "abcdeh", "rzzsss" };
        //vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
        vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
        cout << solution(user_id, banned_id);
        return 0;
    }
}