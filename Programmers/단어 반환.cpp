#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ch[51];
int answer = 2147000000;

// �������� ���� ������ �������� üũ�ϴ� �Լ�
bool isNext(string s, string target) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != target[i]) {
            cnt++;
        }
    }
    if (cnt == 1) {
        return true;
    }
    return false;
}

// dfs�� ��Ʈ��ŷ ����
void dfs(string s, string target, vector<string> &words, int level) {
    if (words.size()+1 < level) return;
    if (s == target) {
        if (answer > level) answer = level;
    }
    else {
        for (int i = 0; i < words.size(); i++) {
            if (!isNext(s, words[i])) continue;
            if (ch[i] == 0) {
                ch[i] = 1;
                dfs(words[i], target, words, level+1);
                ch[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
   
    dfs(begin, target, words, 0);

    // ���� ó�� ���� ���µ��� �ʾ����� �ѹ��� ��������� ���� ���̹Ƿ� 0 ����
    if (answer == 2147000000) {
        return 0;
    }
    return answer;
}

int main() {

    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
    solution(begin, target, words);
    return 0;
}