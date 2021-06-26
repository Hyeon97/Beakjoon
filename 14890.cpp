#include <iostream>
#include <algorithm>


using namespace std;

bool ok, sub;
int N, L, ans;
int map[101][101];//원본
int map2[101][101];//가로세로 반전

void check(int map[][101]) {
	int same = 0;
	for (int y = 0; y < N; y++) {
		ok = true;
		same = 0;
		int prev = -1;
		//순방향(좌 -> 우)
		for (int x = 0; x < N; x++) {
			if (x == 0)same++, prev = map[y][x];
			else {
				if (abs(map[y][x] - prev) > 1) {
					ok = false; break;
				}
				if (map[y][x] > prev) {//오르막
					if (same >= L) same = 1, prev = map[y][x];
					else {
						ok = false; break;
					}
				}
				else if (map[y][x] < prev) {//내리막
					int st = map[y][x], i, cnt;
					bool sub = true;
					for (i = x, cnt = 0; cnt < L; cnt++, i++) {
						if (i >= N || map[y][i] != st) {
							sub = false;
							ok = false;
							break;
						}
					}
					if (sub)x = i - 1, prev = map[y][i - 1], same = 0;
				}
				else {//평지
					same++;
				}
				//if (!ok)break;
			}
		}
		if (ok)ans++;
		else {//순방향에서 길을 찾은경우 역방향은 볼필요 없음
			ok = true;
			same = 0;
			//역방향
			for (int x = N - 1; x >= 0; x--) {
				if (x == N - 1)same++, prev = map[y][x];
				else {
					if (abs(map[y][x] - prev) > 1) {
						ok = false; break;
					}
					if (map[y][x] > prev) {//오르막
						if (same >= L) same = 1, prev = map[y][x];
						else {
							ok = false; break;
						}
					}
					else if (map[y][x] < prev) {//내리막
						int st = map[y][x], i, cnt;
						bool sub = true;
						for (i = x, cnt = 0; cnt < L; cnt++, i--) {
							if (i < 0 || map[y][i] != st) {
								sub = false;
								ok = false;
								break;
							}
						}
						if (sub)x = i + 1, prev = map[y][i + 1], same = 0;
					}
					else {//평지
						same++;
					}
					//if (!ok)break;
				}
			}
			if (ok)ans++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	//현재 지도 상태 입력받음
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			 map2[x][y] = map[y][x];
		}
	}
	check(map);
	check(map2);

	cout << ans;
	return 0;
}
