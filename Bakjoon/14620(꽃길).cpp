//#include <vector>
//#include <iostream>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//int ch[101];
//vector<int> a;
//int n;
//int board[101][101];
//int res = 2147000000;
//bool isOverlap(vector<int> a) {
//    map<int, int> ch;
//    for (int i = 0; i < a.size(); i++) {
//        ch[a[i]]++;
//        if (ch[a[i]] > 1) return true;
//        ch[a[i] + 1]++;
//        if (ch[a[i] + 1] > 1) return true;
//        ch[a[i] - 1]++;
//        if (ch[a[i] - 1] > 1) return true;
//        ch[a[i] - n]++;
//        if (ch[a[i] - n] > 1) return true;
//        ch[a[i] + n]++;
//        if (ch[a[i] + n] > 1) return true;
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
//// https://www.acmicpc.net/problem/14620
//void dfs(int idx) {
//    if (a.size() == 3) {
//        //for (int i = 0; i < a.size(); i++) {
//        //    cout << a[i] << " ";
//        //}
//        //cout << "\n";
//        // 1. ¼¼°³ÀÇ Á¡ÀÇ ÇÉ ²ÉÀÌ °ãÄ¡´ÂÁö È®ÀÎ
//        if (isOverlap(a)) return;
//        res = min(res, calCost(a[0])+calCost(a[1])+calCost(a[2]));
//    }
//    else {
//        for (int i = idx; i < n * n - (n+1) ; i++) {
//            if (ch[i] == 0) {
//                a.push_back(i);
//                ch[i] = 1;
//                dfs(i + 1);
//                a.pop_back();
//                ch[i] = 0;
//            }
//        }
//    }
//}
//int main() {
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> board[i][j];
//        }
//    }
//
//    dfs(n+1);
//
//    cout << res;
//
//    return 0;
//}