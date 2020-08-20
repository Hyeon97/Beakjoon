#include <iostream>
#include <queue>

using namespace std;

int map[9][9], N, M, temp[9][9];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 0;

void virus() {
	int aftervirus[9][9];
	queue<pair<int, int>>vir;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			aftervirus[y][x] = temp[y][x];
			if (temp[y][x] == 2)vir.push({ y,x });
		}
	}
	while (!vir.empty()) {
		int y = vir.front().first;
		int x = vir.front().second;
		vir.pop();
		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if (0 <= Y && Y < N && 0 <= X && X < M && aftervirus[Y][X] == 0) {
				aftervirus[Y][X] = 2;
				vir.push({ Y,X });
			}
		}
	}
	int alive = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!aftervirus[y][x])alive++;

		}
	}
	result = (alive > result) ? alive : result;
}

void Wall(int cnt) {
	//벽을 3개다 세운경우 바이러스 확산 시작
	if (cnt == 3) {
		virus();
		return;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (temp[y][x] == 0) {
				temp[y][x] = 1;
				Wall(cnt + 1);
				temp[y][x] = 0;
			}
		}
	}
}


int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 0) {
				//연구소에서 빈공간인 경우
				//현재 연구소 상태를 복사
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < M; x++) {
						temp[y][x] = map[y][x];
					}
				}
				//그후 벽을 세움
				temp[y][x] = 1;
				Wall(1);
				temp[y][x] = 0;
			}
		}
	}
	cout << result;
	return 0;
}