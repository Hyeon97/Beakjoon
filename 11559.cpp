#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char map[12][6];
bool v[12][6], yes, change;
int combo, num = 0;
//오른쪽 아래 왼쪽 위
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void FIND(int Y, int X, char color) {
	num++;
	v[Y][X] = true;
	//해당 색깔 블록이 4개이상 붙어있는경우
	if (num >= 4)yes = true;
	for (int i = 0; i < 4; i++) {
		int nx = X + dx[i];
		int ny = Y + dy[i];
		//범위안에 있으면서 현재 색과 같은 색인경우
		if (map[ny][nx] == color && !v[ny][nx] && 0 <= ny && ny < 12 && 0 <= nx && nx < 6) {
			FIND(ny, nx, color);
		}
	}
}

void DELETE(int Y, int X, char color) {
	map[Y][X] = '.';
	v[Y][X] = false;
	for (int i = 0; i < 4; i++) {
		int nx = X + dx[i];
		int ny = Y + dy[i];
		//범위안에 있으면서 현재 색과 같은 색인경우
		if (map[ny][nx] == color && v[ny][nx] && 0 <= ny && ny < 12 && 0 <= nx && nx < 6) {

			DELETE(ny, nx, color);
		}
	}
}

void SERACH() {
	change = false;
	for (int y = 11; y > 0; y--) {
		int cnt = 0;
		for (int x = 0; x < 6; x++) {
			if (map[y][x] == '.')cnt++;
			else {
				yes = false;
				num = 0;
				FIND(y, x, map[y][x]);
				//터지는 블럭이 하나도 없는경우 종료
				if (yes) {
					DELETE(y, x, map[y][x]);
					change = true;
				}
			}
		}
		if (cnt == 5)break;
	}
}

void DOWN() {
	for (int col = 0; col < 6; col++) {
		int row_top = 12 - 1;
		for (int row = 12 - 1; row >= 0; row--) {
			if (map[row][col] == '.') continue;
			if (row_top != row) {
				map[row_top][col] = map[row][col];
				map[row][col] = '.';
			}
			row_top--;
		}
	}
}

int main() {

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}

	while (1) {
		//yes = true;
		memset(v, false, sizeof(v));
		SERACH();
		if (change)combo++;
		else break;
		DOWN();
	}

	cout << combo;
	return 0;
}