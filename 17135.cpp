//구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct Dir {
	int y;
	int x;
};

Dir dir[3] = { {0,-1},{-1,0},{0,1} };//좌 상 우
int Y, X, D;
int map[16][16];
int map2[16][16];
bool check[16][16];
bool vi[16][16];
int ans = 0;

void go(int a1, int a2, int a3) {

	int archer[3] = { a1,a2,a3 }; // 현재 궁수 위치 (x축 좌표)
	int pos = Y; // 현재 궁수 위치 (y축 좌표)
	int kill = 0;

	// 맵 복사 + 죽은 적 위치 초기화
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++)
		{
			map2[i][j] = map[i][j];
			check[i][j] = vi[i][j] = false;
		}
	}

	while (pos > 0)//궁수 앞으로 전진
	{
		for (int i = 0; i < 3; i++) // 궁수 3명
		{
			// 방문배열 초기화
			for (int j = 0; j < Y; j++) {
				for (int k = 0; k < X; k++) {
					vi[j][k] = false;
				}
			}

			queue<pair<int, int>>q;
			int x = archer[i];
			int y = pos - 1;

			q.push({ x, y });

			// 적 탐색
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				vi[y][x] = true; // 방문 표시

				if (map2[y][x] == 1) // 적 발견시
				{
					check[y][x] = true; // 공격 표시
					break;
				}

				for (int j = 0; j < 3; j++) // 좌,상,우
				{
					int nx = x + dir[j].x;
					int ny = y + dir[j].y;
					// 갈려는 곳이 맵 범위안 + 궁수 사정거리안 + 방문한적 없음 
					if (0 <= nx && nx < X && 0 <= ny && ny < Y && ((abs(archer[i] - nx) + abs(pos - ny) <= D)) && !vi[ny][nx])
						q.push({ nx, ny });
				}
			}
		}

		// 공격 표시된 적들 제거
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (check[i][j]) map2[i][j] = 0;
			}
		}
		pos--; // 궁수들 전진
	}

	// 죽은 적 카운트
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (check[i][j]) kill++;
		}
	}
	ans = max(ans, kill);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X >> D;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
		}
	}
	//궁수 위치
	for (int i = 0; i < X; i++) {
		for (int j = i + 1; j < X; j++) {
			for (int k = j + 1; k < X; k++) {
				go(i, j, k);//궁수 3명 위치
			}
		}
	}

	cout << ans;
	return 0;
}
