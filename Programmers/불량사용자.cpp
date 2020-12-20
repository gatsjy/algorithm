#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

namespace _�ҷ������ {
    vector<pair<string, vector<string>>> list;

    // ������ ���̵����� Ȯ�� �ϴ� �޼���
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

    // ch[8]�ΰ� ������ ���Ʈ������ ������..
    string ch[8];

    // �ش� �迭�� �ߺ��� �ִ��� Ȯ�� -> �ߺ��� ������ Ż��
    bool isDouble() {
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (ch[i] == ch[j]) return true;
            }
        }
        return false;
    }

    // set�� �̿��ؼ� ���ϴ� ������ �ߺ����� üũ
    set<string> resstring;

    // �θ�Ʈ ������ ��� ����� �� Ž��
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

        // user_id �� banned_id�� �����ִ��� �Ǵ��ϱ�
        for (int i = 0; i < banned_id.size(); i++) {
            vector<string> tmp;
            for (int j = 0; j < user_id.size(); j++) {
                if (isBanned(banned_id[i], user_id[j])) {
                    tmp.push_back(user_id[j]);
                }
            }
            list.push_back({ banned_id[i], tmp });
        }

        // ch�迭 -1�� �ʱ�ȭ
        for (int i = 0; i < 8; i++) {
            ch[i] = "-1";
        }

        // �ϴ� dfs�� ������ �� �������� string ���� ������
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