#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

vector<string> splitString(string s) {
    vector<string> ss;
    for (int i = 0; i < s.size() - 1; i++) {
        string tmp = "";
        if (!isalpha(s[i]) || !isalpha(s[i + 1])) continue;
        tmp += s[i];
        tmp += s[i + 1];
        ss.push_back(tmp);
    }
    return ss;
}
int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<string> ss1 = splitString(str1);
    vector<string> ss2 = splitString(str2);
    vector<string> res = ss2;
    int cnt = 0;
    for (int i = 0; i < ss1.size(); i++) {
        vector<string>::iterator itor = find(res.begin(), res.end(), ss1[i]);
        if (itor != res.end()) {
            cnt++;
            res.erase(itor);
        }
    }

    if (ss1.size() == 0 && ss2.size() ==0) return 65536;
    answer = 65536 * (double)cnt / (double)(ss1.size() + ss2.size() - cnt);

    return answer;
}

int main() {
    string s1 = "FRANCE";
    string s2 = "french";

    solution(s1, s2);

    return 0;
}