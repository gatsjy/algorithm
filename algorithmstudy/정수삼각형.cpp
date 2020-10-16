#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147000000
#define max_v 20001
#define max_e 300001

typedef struct Node {
    int togo;
    int val;
};

vector<Node> map[max_v];
int dist[max_e];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, start;

    cin >> n >> e >> start;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    int from, to, val;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> val;
        map[from].push_back(Node{ to,val });
    }

    // val, togo
    priority_queue<pair<int, int>> pq;

    pq.push({ 0, start });

    while (!pq.empty()) {
        int togo = pq.top().second;
        int val = -1 * pq.top().first;
        pq.pop();
        for (int i = 0; i < map[togo].size(); i++) {
            int previous_val = dist[togo];
            int new_val = val + dist[map[togo][i].val];

            if (new_val > new_val) {
                pq.push({ -1 * new_val, map[togo][i].togo });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }
}