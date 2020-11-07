#include <bits/stdc++.h>

using namespace std;


vector<int> solution_°èÁÂ(int money) {
	int moneys[9] = { 50000,10000,5000,1000,500,100,50,10,1 };
	vector<int> answer(9);
	for (int i = 0; i < 9; i++) {
		answer[i] = money / moneys[i];
		money = money % moneys[i];
	}
	return answer;
}