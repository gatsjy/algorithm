#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    sort(times.begin(), times.end());
    unsigned long long lt = 1;
    unsigned long long rt = times[times.size() - 1] * n;

    while (lt <= rt) {
        unsigned long long mid = (lt + rt) / 2;
        unsigned long long cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        if (n <= cnt) {
            rt = mid - 1;
            if (answer == 0) {
                answer = mid;
            }
            else {
                answer = min(answer, mid);
            }
        }
        else {
            lt = mid + 1;
        }
    }
    return answer;
}