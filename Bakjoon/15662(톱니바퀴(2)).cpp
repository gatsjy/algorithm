#include <vector>
#include <iostream>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/15662
// 2021-02-03, ���־�, �ϴ� �� ������ �ذ� �Ϸ�! -> �ٵ� �ʹ����� ��ȿ�����̴�!!
// ���� ȿ������ ����� ã�Ƽ�.. na982���� ���Ǹ� �� ����

namespace _15662 {
	typedef struct Tob {
		int clockwise = -1; // -1 : �ʱ���� / 1 : �ð���� / 0 : �ð�ݴ����
		int thiscnt = -1; // �̹��Ͽ� ȸ���� �ߴ��� ���ߴ��� ��Ÿ���� �÷��װ�
		vector<vector<int>> pos = vector<vector<int>>(3, vector<int>(3, 0));
	};

	// ��� ���� ������ �޼���
	// 1. flag = 1 �ð����
	// 2. flag = -1 �ð�ݴ����
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
			a--; // �ε����� �ϳ� �ٿ��ش�.

			// 1. �ϴ� ������ ����� ���� �������ش�.
			if (c[0] == '-') {
				tobs[a].clockwise = false;
			}
			else
			{
				tobs[a].clockwise = true;
			}

			// 1-2. �̹����� cnt���� �Ҵ�����(cnt�� ������ ���� ��ϸ� ������)
			tobs[a].thiscnt = cnt;

			// 2. �������� ���� ����
			for (int i = a - 1; i >= 0; i--) {
				if (tobs[i + 1].pos[1][0] != tobs[i].pos[1][2]) {
					tobs[i].clockwise = !tobs[i + 1].clockwise;
					tobs[i].thiscnt = cnt;
				}
				else {
					break;
				}
			}
			// 3. �������� ���� ����
			for (int i = a + 1; i < n; i++) {
				if (tobs[i - 1].pos[1][2] != tobs[i].pos[1][0]) {
					tobs[i].clockwise = !tobs[i - 1].clockwise;
					tobs[i].thiscnt = cnt;
				}
				else {
					break;
				}
			}

			// 4. �̹��� ���
			for (int i = 0; i < n; i++) {
				if (tobs[i].clockwise == -1) continue;
				if (tobs[i].thiscnt != cnt) continue;
				rotateClockWise(tobs[i].pos, tobs[i].clockwise);
			}
		}

		int cnt = 0;

		// 5. 12�� ���� üũ
		for (int i = 0; i < n; i++) {
			if (tobs[i].pos[0][1] == 1) cnt++;
		}

		cout << cnt;

		return 0;
	}
}
