#include <iostream>

using namespace std;
int n;

void recur(int i) {
	if (i == n+1) return;
	cout << i << " ";
	return recur(i + 1);
}

int main() {
	cin >> n;
	recur(1);
}