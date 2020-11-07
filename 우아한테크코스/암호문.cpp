#include <bits/stdc++.h>

using namespace std;

string solution(string word) {
	string res = "";
	while (1) {
		for (int i = 1; i < word.size(); i++) {
			if (word[i] == word[i - 1]) {
				word.erase(word.begin() + i - 1, word.begin() + i + 1);
				i--;
				cout << word << "\n";
				continue;
			}
			if (i == word.size()) {
				cout << word;
				break;
			}
		}

	}

	return res;
}
int main() {

	string s = "browoanoommnaon";
	solution(s);
	return 0;
}
