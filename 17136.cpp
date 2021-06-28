//구현
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;


int s[6] = { 0,5,5,5,5,5 };//각 크기의 색종이 수 보유량
int map[10][10];
int ans,cnt;
void DFS(int X, int Y) {
	if (X == 10) {//x축 한줄 다읽음 >> 아랫줄로 이동
		DFS(0, Y + 1);
		return;
	}
	if (Y == 10) {//y축 끝까지 다내려옴 >> 탐색 종료
		ans = min(ans,cnt);
		return;
	}
	if (map[Y][X] == 0) {// 해당지점이 0인경우 탐색할 필요 없음 >> 이동
		DFS(X + 1, Y);
		return;
	}

	//5가지 종류의 색종이 모두 사용해봄
	for (int i = 5; i > 0; i--) {

		//범위초과 또는 해당크기의 남은 색종이가 없는경우 탐색X
		if (X + i > 10 || Y + i > 10 || s[i]==0)continue;
		bool no = false;
		for (int y = Y; y < Y + i; y++) {
			for (int x = X; x < X + i; x++) {
				if (map[y][x] == 0) {
					no = true; break;
				}
			}
			if (no)break;
		}
		if (!no) {//덮을수 있는 경우
			//덮어줌
			for (int y = Y; y < Y + i; y++) {
				for (int x = X; x < X + i; x++) {
					map[y][x] = 0;
				}
			}
			s[i]--;//해당 크기 색종이 수 감소
			cnt++;
			DFS(X+i,Y);

			//덮은 색종이 치움
			for (int y = Y; y < Y + i; y++) {
				for (int x = X; x < X + i; x++) {
					map[y][x] = 1;
				}
			}
			s[i]++;
			cnt--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	ans = INF;
	DFS(0, 0);
	ans == INF ? cout << -1 : cout << ans;
	return 0;
}
