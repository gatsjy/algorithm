#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

// k��° ���̳밡 ��������, k-1��° ���̳밡 ��������.... 2��° ���̳밡 ��������.. 1��° ���̳밡 ��������.

namespace _17478 {
	int n;
	void printUnderBar(int x) {
		int cnt = x * 4;
		for (int i = 0; i < cnt; i++) {
			cout << "_";
		}
	}

	void func(int x) {
		if (x == n) {
			printUnderBar(x); cout << "\"����Լ��� ������?\"" << "\n";
			printUnderBar(x); cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
			printUnderBar(x); cout << "��� �亯�Ͽ���." << "\n";
			return;
		}
		printUnderBar(x); cout << "\"����Լ��� ������?\"" << "\n";
		printUnderBar(x); cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
		printUnderBar(x); cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
		printUnderBar(x); cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
		func(x + 1);
		printUnderBar(x); cout << "��� �亯�Ͽ���." << "\n";
	}
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
		func(0);
		return 0;
	}
}
