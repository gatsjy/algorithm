#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

namespace _31 {
    int main() {

        int res = 0;
        string tmp = "0";

        string s;
        cin >> s;
        bool flag = false;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                tmp += s[i];
            }
            else {
                if (!flag) {
                    if (tmp == "0") {
                        res += 12;
                    }
                    else {
                        res += stoi(tmp) * 12;
                    }
                    flag = true;
                }
                tmp = "0";
            }
        }
        if (tmp == "0") {
            res += 1;
        }
        else {
            res += stoi(tmp);
        }
        cout << res;
        return 0;
    }
}
