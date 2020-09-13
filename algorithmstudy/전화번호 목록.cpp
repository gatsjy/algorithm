#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace programmers_전화번호목록 {
    bool solution(vector<string> phoneBook) {
        bool answer = true;
        sort(phoneBook.begin(), phoneBook.end());

        for (int i = 0; i < phoneBook.size() - 1; i++) {
            if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) {
                answer = false;
                break;
            }
        }

        return answer;
    }
    int main() {
        vector<string> book1 = { "019", "97674223", "0195524421" };
        vector<string> book2 = { "123", "456", "789" };
        vector<string> book3 = { "12", "123", "1235", "567", "88" };
        cout << solution(book1) << endl;
    }
}