//#include <vector>
//#include <iostream>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int dx[4] = { 1,0,-1,0};
//int dy[4] = { 0,1,0,-1};
//
//int ch[101];
//vector<int> a;
//int n;
//int board[101][101];
//int res = 2147000000;
//bool isOverlap(vector<int> tmp) {
//    int dch[101] = { 0, };
//    for (int i = 0; i < a.size(); i++) {
//        dch[tmp[i] + 1]++;
//        dch[tmp[i] - 1]++;
//        dch[tmp[i] + n]++;
//        dch[tmp[i] - n]++;
//        dch[tmp[i]]++;
//    }
//    for (int i = 0; i < 101; i++) {
//        if (dch[i] > 1) return true;
//    }
//    return false;
//}
//
//int calCost(int cnt) {
//    pair<int, int> cur = { cnt / n,cnt % n };
//    int sum = board[cur.first][cur.second];
//    for (int i = 0; i < 4; i++) {
//        sum += board[cur.first + dx[i]][cur.second + dy[i]];
//    }
//    return sum;
//}
//
//int main() {
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> board[i][j];
//        }
//    }
//
//    for (int i = 1; i < n * n - (n + 1); i++) {
//        for (int j = i + 1; j < n * n - (n + 1); j++) {
//            for(int k = j+1; k < n * n - (n + 1); k++){
//                vector<int> tmp;
//                tmp.push_back(i);
//                tmp.push_back(j);
//                tmp.push_back(k);
//                if (!isOverlap(tmp)) {
//                    res = min(res, calCost(i)+ calCost(j)+ calCost(k));
//                    cout << res << "\n";
//                }
//            }
//        }
//    }
//
//    cout << res;
//
//    return 0;
//}