#include <iostream>

using namespace std;

int n,cnt;
int ch[200001];
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (ch[i]) continue;
		for (int k = 2; k * i <= n; k++) {
			if (!ch[k * i]) ch[k * i] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!ch[i]) {
			cnt++;
			//cout << i << "\n";
		}

	}
	cout << cnt;
	return 0;
}