#include <bits/stdc++.h>

namespace _20001 {
	using namespace std;

	int main() {
		stack<string> st;
		string input;
		while (getline(cin, input)) {
			if (input == "������ ����� ��") {
				break;
			}
			else if (input == "������ ����� ����") {
				continue;
			}
			else {
				if (input == "����") {
					st.push("����");
				}
				else {
					if (st.empty()) {
						st.push("����");
						st.push("����");
					}
					else {
						st.pop();
					}
				}
			}
		}
		if (st.empty()) {
			cout << "�������� �����";
		}
		else {
			cout << "����";
		}
		return 0;
	}
}