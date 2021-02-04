#include <vector>
#include <iostream>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/15662
// 2021-02-03, 한주안, 일단 내 힘으로 해결 완료! -> 근데 너무나도 비효율적이다!!
// 좀더 효율적인 방안을 찾아서.. na982님의 강의를 볼 예정

namespace _15662 {
	typedef struct Tob {
		int clockwise = -1; // -1 : 초기상태 / 1 : 시계방향 / 0 : 시계반대방향
		int thiscnt = -1; // 이번턴에 회전을 했는지 안했는지 나타내는 플래그값
		vector<vector<int>> pos = vector<vector<int>>(3, vector<int>(3, 0));
	};

	// 톱니 방향 돌리는 메서드
	// 1. flag = 1 시계방향
	// 2. flag = -1 시계반대방향
	void rotateClockWise(vector<vector<int>>& pos, bool flag) {
		vector<vector<int>> tmp = vector<vector<int>>(3, vector<int>(3, 0));
		if (flag) {
			tmp[0][0] = pos[1][0];
			tmp[0][1] = pos[0][0];
			tmp[0][2] = pos[0][1];
			tmp[1][0] = pos[2][0];
			tmp[1][2] = pos[0][2];
			tmp[2][0] = pos[2][1];
			tmp[2][1] = pos[2][2];
			tmp[2][2] = pos[1][2];
		}
		else {
			tmp[0][0] = pos[0][1];
			tmp[0][1] = pos[0][2];
			tmp[0][2] = pos[1][2];
			tmp[1][0] = pos[0][0];
			tmp[1][2] = pos[2][2];
			tmp[2][0] = pos[1][0];
			tmp[2][1] = pos[2][0];
			tmp[2][2] = pos[2][1];
		}

		pos[0][0] = tmp[0][0];
		pos[0][1] = tmp[0][1];
		pos[0][2] = tmp[0][2];
		pos[1][0] = tmp[1][0];
		pos[1][2] = tmp[1][2];
		pos[2][0] = tmp[2][0];
		pos[2][1] = tmp[2][1];
		pos[2][2] = tmp[2][2];
	}

	Tob makeTobs(string s) {
		Tob tob;
		tob.pos[0][0] = s[7] - '0';
		tob.pos[0][1] = s[0] - '0';
		tob.pos[0][2] = s[1] - '0';
		tob.pos[1][0] = s[6] - '0';
		tob.pos[1][2] = s[2] - '0';
		tob.pos[2][0] = s[5] - '0';
		tob.pos[2][1] = s[4] - '0';
		tob.pos[2][2] = s[3] - '0';
		return tob;
	}

	int n, k, cnt;
	string s;
	int main() {

		cin >> n;
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<Tob> tobs;

		for (int i = 0; i < n; i++) {
			cin >> s;
			tobs.push_back(makeTobs(s));
		}

		cin >> k;

		for (int i = 0; i < k; i++) {
			cnt++;
			int a; string c;
			cin >> a >> c;
			a--; // 인덱스를 하나 줄여준다.

			// 1. 일단 지정된 톱니의 방향 결정해준다.
			if (c[0] == '-') {
				tobs[a].clockwise = false;
			}
			else
			{
				tobs[a].clockwise = true;
			}

			// 1-2. 이번턴의 cnt값을 할당해줌(cnt가 동일한 값만 톱니를 돌린다)
			tobs[a].thiscnt = cnt;

			// 2. 기준으로 좌측 전파
			for (int i = a - 1; i >= 0; i--) {
				if (tobs[i + 1].pos[1][0] != tobs[i].pos[1][2]) {
					tobs[i].clockwise = !tobs[i + 1].clockwise;
					tobs[i].thiscnt = cnt;
				}
				else {
					break;
				}
			}
			// 3. 기준으로 우측 전파
			for (int i = a + 1; i < n; i++) {
				if (tobs[i - 1].pos[1][2] != tobs[i].pos[1][0]) {
					tobs[i].clockwise = !tobs[i - 1].clockwise;
					tobs[i].thiscnt = cnt;
				}
				else {
					break;
				}
			}

			// 4. 이번턴 결산
			for (int i = 0; i < n; i++) {
				if (tobs[i].clockwise == -1) continue;
				if (tobs[i].thiscnt != cnt) continue;
				rotateClockWise(tobs[i].pos, tobs[i].clockwise);
			}
		}

		int cnt = 0;

		// 5. 12시 방향 체크
		for (int i = 0; i < n; i++) {
			if (tobs[i].pos[0][1] == 1) cnt++;
		}

		cout << cnt;

		return 0;
	}
}
