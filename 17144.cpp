#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Y, X, T;
int map[51][51];
int sp[51][51];//임시 먼지 분산값 저장
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool Ac;
pair<int, int> Acc;//공기청정기 머리 좌표(위쪽)

void spray() {
	//각 자리 먼지 확산(out)
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x]>0) {//해당위치에 먼지가 존재하는 경우 >> 확산
				int out = map[y][x] / 5;//소숫점은 버림
				//4방향 확산
				int cnt = 0;
				for (int D = 0; D < 4; D++) {
					int nx = x + dx[D];
					int ny = y + dy[D];
					if ( nx < 0 || ny < 0 || nx > X-1 || ny > Y-1  || map[ny][nx]==-1)continue;//범위 초과 or 공기청정기 있는곳은 못감
					sp[ny][nx] += out;//그외 공간 확산값 더해줌
					cnt++;
				}
				//확산하고 남은양
				map[y][x] -= out * cnt;
			}
		}
	}
	//각 자리 먼지 확산(in)
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] == -1)continue;
			map[y][x] += sp[y][x];
			sp[y][x] = 0;
		}
	}
}

void move() {//해당라인부터 테두리만 움직임
	//공기청청기 위쪽 먼지 움직임
	int x=Acc.second, y=Acc.first;
	for (y-1; y > 0; y--) {
		if (map[y][x] == -1)continue;
		map[y][x] = map[y - 1][x];
	}
	for (x; x < X-1; x++) {
		map[y][x] = map[y][x + 1];
	}
	for (y; y < Acc.first; y++) {
		map[y][x] = map[y + 1][x];
	}
	for (x; x > 0; x--) {
		if (map[y][x-1] == -1)map[y][x]=0;
		else map[y][x] = map[y][x - 1];
	}
	//map[y][x] = 0;
	//공기청정기 아래쪽 먼지 움직임
	x = Acc.second, y = Acc.first+1;
	for (y + 1; y < Y-1; y++) {
		if (map[y][x] == -1)continue;
		map[y][x] = map[y + 1][x];
	}
	for (x; x < X-1; x++) {
		map[y][x]=map[y][x + 1];
	}
	for (y; y > Acc.first + 1; y--) {
		map[y][x] = map[y - 1][x];
	}
	for (x; x > 0; x--) {
		if (map[y][x - 1] == -1)map[y][x] = 0;
		else map[y][x] = map[y][x - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X >> T;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
			if (!Ac && map[y][x] == -1) {//해당위치에 공기청정기 존재하는 경우
				Acc = { y,x };
				Ac = true;
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		spray();//먼지 확산
		move();//공기청정기 동작
	}
	//남은 미세먼지 총합
	int ans = 0;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] > 0)ans += map[y][x];
		}
	}
	cout << ans;
	return 0;
}
