#include <bits/stdc++.h>

using namespace std;

int n;

int score1[2881];
int score2[2881];

int team1ss, team2ss;
int team1score, team2score;

int main() {

	cin >> n;
	// 와 이거 어케 세냐?
	while (n--) {
		string team, hour;
		cin >> team;
		cin >> hour;

		// 농구경기는 48분 즉 48*60=2880초 진행
		int hh = stoi(hour.substr(0,2));
		int ss = stoi(hour.substr(3));
		
		if (team == "1") {
			score1[hh * 60 + ss] = 1;
		}
		else {
			score2[hh * 60 + ss] = 1;
		}
	}

	for (int i = 1; i < 2880; i++) {
		if (score1[i] == 1) {
			team1score++;
		}
		if (score2[i] == 1) {
			team2score++;
		}
		if (team1score > team2score) {
			team1ss++;
		}
		if (team1score < team2score) {
			team2ss++;
		}
	}

	cout << ((team1ss/60 == 0) ? "00" : to_string(team1ss / 60)) + ":" << ((team1ss % 60 == 0) ? "00" : to_string(team1ss % 60)) << "\n";
	cout << ((team2ss/60 == 0) ? "00" : to_string(team2ss / 60)) + ":" << ((team2ss % 60 == 0) ? "00" : to_string(team2ss % 60)) << "\n";

	return 0;
}