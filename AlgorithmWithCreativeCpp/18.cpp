#include <iostream>

using namespace std;

int n, m;
int max_cnt, cnt;
int tmp;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > m)cnt++;
		else
		{
			if (max_cnt < cnt) {
				max_cnt = cnt;
				cnt = 0;
			}
		}
	}
	cout << max_cnt;
	return 0;
}