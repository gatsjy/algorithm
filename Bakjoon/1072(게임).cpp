#include <bits/stdc++.h>

using namespace std;

// 이분검색을 사용하는이유가 무엇일까?
// 1~100을 검색하한다고 생각하면 특정 수를 찾는 알고리즘은 
// 하나씩 검색하면 n / 하지만 반씩 줄어들어가면 log2n
long long x, y;
long long res = 2147000000;
int main() {
	cin >> x >> y;
	long long lt = 1;
	long long rt = 1000000000;

	//int wrate = (int)(((float)y / (float)x) * 100)+1;
	int wrate = y * 100 / x + 1;

	if (wrate >= 100) {
		res = 1;
	}else{
		// 이분 검색 시작..
		while (lt <= rt) {
			long long mid = (lt + rt) / 2;
			// twrate == temp win rate
			int twrate = (int)((((float)y + mid) / ((float)x + mid)) * 100);
			if (twrate >= wrate) {
				rt = mid - 1;
				res = min(mid, res);
			}
			else {
				lt = mid + 1;
			}
		}
	}
	
	cout << res;
	return 0;
}