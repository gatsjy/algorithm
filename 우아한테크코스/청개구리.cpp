#include <bits/stdc++.h>
namespace _청개구리 {
	using namespace std;
	char changeWord(char c) {
		int counter = c - 'A' + 1;
		return c + 25 - ((c - 'A') * 2);
	}

	string solution(string word) {
		string answer = "";

		// 25-(char-'A')*2
		// 'A' == 65 -> 'Z' == 90 -> +25 (-0)
		// 'B' == 66 -> 'Y' == 89 -> +23 (-2)
		// 'C' == 67 -> 'X' == 88 -> +21 (-4)
		// 'D' == 68 -> 'W' == 87 -> +19 (-6)
		// ...
		// 'Z' == 90 -> 'A' == 65 -> -25 (-50)
		for (int i = 0; i < word.size(); i++) {
			if (word[i] == ' ') {
				answer += ' ';
			}
			else if (islower(word[i])) {
				answer += tolower(changeWord(toupper(word[i])));
			}
			else if (isupper(word[i])) {
				answer += changeWord(word[i]);
			}
		}

		return answer;
	}
	int main() {
		string s = "I love you";
		solution(s);
		return 0;
	}
}