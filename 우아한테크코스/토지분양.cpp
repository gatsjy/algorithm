#include <vector>
#include <algorithm>
#include <iostream>

namespace _�����о� {
	using namespace std;
	bool isInclude(pair<pair<int, int>, pair<int, int>> land, pair<pair<int, int>, pair<int, int>> target) {
		// ���ǻ� 4���� ������ ���� 
		// a->1��и�, b->2��и�, c->3��и�, d->4��и�
		pair<int, int> a = land.second;
		pair<int, int> b = { land.first.first, land.second.second };
		pair<int, int> c = land.first;
		pair<int, int> d = { land.second.first, land.first.second };

		// �� ���� ��� ���ԵǾ� ������ target�� ���ԵǾ��ִٰ� �Ǵ�.
		// 1. ù��° ��
		pair<int, int> target1 = target.first;
		// 2. �ι�° ��
		pair<int, int> target2 = target.second;

		bool flag = true;
		// ���ԵǾ��ִ��� �Ǵ��ϴ� �κ�
		if (!((target1.first > c.first && target1.first < d.first) && (target1.second > c.second && target1.second < b.second))) {
			flag = false;
		}

		if (!((target2.first > c.first && target2.first < d.first) && (target2.second > c.second && target2.second < a.second))) {
			flag = false;
		}

		return flag;
	}


	bool solution(vector<pair<pair<int, int>, pair<int, int>>> land, vector<pair<pair<int, int>, pair<int, int>>> wells, pair<pair<int, int>, pair<int, int>> point) {

		// 1. point�� lands���� ���Ե��� �ʴ´�.
		for (int i = 0; i < land.size(); i++) {
			if (isInclude(land[i], point)) {
				return false;
			}
		}

		// 2. point�� wells���� ���Եȴ�.
		for (int i = 0; i < wells.size(); i++) {
			if (isInclude(point, wells[i])) {
				return true;
			}
		}

		return false;
	}

	int main() {
		vector<pair<pair<int, int>, pair<int, int>>> lands = { {{0,30},{20,50}},{{30,30},{40,40}} };
		vector<pair<pair<int, int>, pair<int, int>>> wells = { {{15,15},{25,25}},{{40,10},{50,20}} };
		//pair<pair<int, int>,pair<int,int>> point = {{10,10},{30,30}};
		pair<pair<int, int>, pair<int, int>> point = { {30,30},{40,30} };
		cout << solution(lands, wells, point) << endl;
		return 0;
	}
}
