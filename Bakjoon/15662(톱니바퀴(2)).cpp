#include <vector>
#include <iostream>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/15662

typedef struct Tob {
    int clockwise = -1;
    vector<vector<int>> pos = vector<vector<int>>(3, vector<int>(3, 0));
};

// 시계방향으로
void rotateClockWise(vector<vector<int>> &pos, bool flag) {
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

int n,k;
string s;
int main() {

    cout << !1;
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
        int a; string c;
        cin >> a >> c;
        a--;
        if (c[0] == '-') {
            rotateClockWise(tobs[a].pos, false);
            tobs[a].clockwise = false;

        }
        else 
        {
            rotateClockWise(tobs[a].pos, true);
            tobs[a].clockwise = true;
        }
        // 좌측 전파
        for (int i = a - 1; i >= 0; i--) {
            if (tobs[i + 1].pos[1][2] != tobs[i].pos[1][0]) {
                tobs[i].clockwise = !tobs[i + 1].clockwise;
            }
        }
        // 우측 전파
        for (int i = a + 1; i < n; i++) {
            if (tobs[i - 1].pos[1][0] != tobs[i].pos[1][2]) {
                tobs[i].clockwise = !tobs[i - 1].clockwise;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == a)continue;
            rotateClockWise(tobs[i].pos, tobs[i].clockwise);
        }
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tobs[i].pos[0][1] == 1) cnt++;
    }

    cout << cnt;

    return 0;
}