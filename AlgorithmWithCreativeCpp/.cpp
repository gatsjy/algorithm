#include <bits/stdc++.h>

using namespace std;

int main() {

    stack<int> st;
    int i, j = 1, n, m;
    cin >> n;
    vector<char> str;

    for (i = 1; i <= n; i++) {
        scanf_s("%d", &m);
        st.push(m);
        str.push_back('P');
        while (1) {
            if (st.empty()) break;
            if (j == st.top()) {
                st.pop();
                str.push_back('O');
                j++;
            }
            else {
                break;
            }
        }
    }
    if (!st.empty()) printf("impossible");
    else {
        for (i = 0; i < str.size(); i++) {
            cout << str[i];
        }
    }
}