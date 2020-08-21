#include <iostream>

using namespace std;

int w, h;
//0�̸� ���� 1�̸� ����, 0�̸� 1ĭ 1�̸� 2ĭ
int map[111][111][2][2];

int main() {
	cin >> w >> h;

	for (int i = 2; i <= w; i++)map[i][1][0][0] = 1;
	for (int i = 2; i <= h; i++)map[1][i][1][0] = 1;

	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {

			map[i][j][0][0] = (map[i - 1][j][0][0] + map[i - 1][j][0][1]) % 100000;
			map[i][j][0][1] = map[i - 1][j][1][0];
			map[i][j][1][0] = (map[i][j - 1][1][0] + map[i][j - 1][1][1]) % 100000;
			map[i][j][1][1] = map[i][j - 1][0][0];

		}
	}
	cout << (map[w][h][0][0] + map[w][h][0][1] + map[w][h][1][0] + map[w][h][1][1]) % 100000;
	return 0;
}