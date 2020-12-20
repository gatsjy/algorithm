#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ch[51];
int answer = 2147000000;

// 다음으로 진행 가능한 문자인지 체크하는 함수
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

// dfs로 백트래킹 구현
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

    // 만약 처음 값이 리셋되지 않았으면 한번도 진행된적이 없단 말이므로 0 리턴
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