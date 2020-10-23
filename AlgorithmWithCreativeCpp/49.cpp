#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    int total = 0;
    for (int i = 0; i < food_times.size(); i++) {
        total += food_times[i];
    }

    if (total < k) {
        return -1;
    }
    int time = 0;
    int pos = -1;
    while (1) {
        pos++;
        if (pos == food_times.size()) pos = 0;
        if (food_times[pos] == 0) continue;
        food_times[pos]--;
        time++;
        if (time == k) break;
    }
    while (1) {
        pos++;
        if (pos == food_times.size()) pos = 0;
        if (food_times[pos] != 0) break;
    }
    return pos + 1;
}

int main() {
    vector<int> v = { 3,1,2 };
    long long k = 5;
    solution(v, k);
    return 0;
}