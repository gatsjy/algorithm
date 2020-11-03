#include <bits/stdc++.h>

namespace _20001 {
	using namespace std;

	int main() {
		stack<string> st;
		string input;
		while (getline(cin, input)) {
			if (input == "고무오리 디버깅 끝") {
				break;
			}
			else if (input == "고무오리 디버깅 시작") {
				continue;
			}
			else {
				if (input == "문제") {
					st.push("문제");
				}
				else {
					if (st.empty()) {
						st.push("문제");
						st.push("문제");
					}
					else {
						st.pop();
					}
				}
			}
		}
		if (st.empty()) {
			cout << "고무오리야 사랑해";
		}
		else {
			cout << "힝구";
		}
		return 0;
	}
}