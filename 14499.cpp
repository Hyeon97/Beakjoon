#include <iostream>

using namespace std;

//  2    |  1
//4 1 3  |3 0 2
//  5    |  4
//  6    |  5

int n, m, x, y, k, map[21][21], dice[6], q;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool chk(int cx, int cy) {
	return 0 <= cx && cx < n && 0 <= cy && cy < m;
}

void get(int dir) {
	int tdice[6];
	for (int i = 0; i < 6; i++) {
		tdice[i] = dice[i];
	}
	if (dir == 1) {
		dice[0] = tdice[3];
		dice[3] = tdice[5];
		dice[5] = tdice[2];
		dice[2] = tdice[0];
	}
	else if (dir == 2) {
		dice[0] = tdice[2];
		dice[2] = tdice[5];
		dice[5] = tdice[3];
		dice[3] = tdice[0];
	}
	else if (dir == 3) {
		dice[0] = tdice[4];
		dice[4] = tdice[5];
		dice[5] = tdice[1];
		dice[1] = tdice[0];
	}
	else if (dir == 4) {
		dice[0] = tdice[1];
		dice[1] = tdice[5];
		dice[5] = tdice[4];
		dice[4] = tdice[0];
	}
}


void sp() {
	if (map[x][y]) {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
	else
		map[x][y] = dice[5];
}

int main() {
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int temp;
	//이동후 출력
	for (int i = 0; i < k; i++) {
		cin >> temp;
		int nx = x + dx[temp - 1];
		int ny = y + dy[temp - 1];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			x = nx;
			y = ny;
			get(temp);
			sp();
			cout << dice[0] << '\n';
		}
	}

	return 0;
}