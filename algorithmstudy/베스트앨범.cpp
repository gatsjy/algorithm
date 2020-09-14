#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

namespace programmers_bestAlbum {
    bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
wndksdl
    bool compare_map_value(pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    }

    vector<int> solution(vector<string> genres, vector<int> plays) {
        vector<int> answer;

        // genres_cnt
        map<string, int> genres_cnt;
        map<string, vector<pair<int, int>>> genres_plays;
        vector<pair<string, int>> genres_cnt_v;

        for (int i = 0; i < genres.size(); i++) {
            genres_cnt[genres[i]] += plays[i];
            genres_plays[genres[i]].push_back(make_pair(plays[i], i));
        }

        // 여기서 정렬이 중요하다.
        // 장르별로 재생 횟수를 내림차순으로 정렬
        for (auto& cur : genres_plays) {
            sort(cur.second.begin(), cur.second.end(), compare);
        }

        // 장르별 총 재생횟수를 내림차순으로 정렬
        genres_cnt_v.assign(genres_cnt.begin(), genres_cnt.end()); // 정렬해주기 위해 할당 시킨다.
        sort(genres_cnt_v.begin(), genres_cnt_v.end(), compare_map_value);

        // 2개씩 뽑아내서 answer에 저장
        for (int i = 0; i < genres_cnt_v.size(); i++) {
            if (genres_plays[genres_cnt_v[i].first].size() >= 2) {
                for (int j = 0; j < 2; j++) {
                    answer.push_back(genres_plays[genres_cnt_v[i].first][j].second);
                }
            }
            else {
                answer.push_back(genres_plays[genres_cnt_v[i].first][0].second);
            }
        }
        return answer;
    }

    int main() {
        vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
        vector<int> plays = { 500, 600, 150, 800, 2500 };

        solution(genres, plays);
        return 0;
    }
}
