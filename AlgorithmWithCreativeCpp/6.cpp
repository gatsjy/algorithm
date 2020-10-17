#include <iostream>
#include <string>

using namespace std;

namespace _6 {
	int main() {
		string s;

		cin >> s;

		string target = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				target += s[i];
			}
		}
		int targetm = stoi(target);
		cout << targetm << endl;
		int cnt = 0;
		for (int i = 1; i <= targetm; i++) {
			if (targetm % i == 0) {
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
}
