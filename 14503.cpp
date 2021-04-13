#include <iostream> 
#include <queue> 
#include <vector> 
#include <algorithm> 

using namespace std;
const int MAX = 50;
typedef struct { int y, x; }Dir;

Dir moveDir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // N E S W 
int N, M; int map[MAX][MAX];
int r, c, d;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r, c}, d });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second;
		if (!map[y][x]) {
			map[y][x] = 2;//벽은 1 청소완료 2
			cnt++;
		}
		q.pop();
		bool Clean = false;
		for (int i = 0; i < 4; i++) { //좌회전을 모듈연산
			int nextDir = (dir + 3 - i) % 4;
			int nextY = y + moveDir[nextDir].y;
			int nextX = x + moveDir[nextDir].x;
			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && !map[nextY][nextX]) {
				q.push({ {nextY, nextX}, nextDir }); 
				Clean = true; 
				break;
			}
		} //네 방향 다 청소되어 있는 경우 
		if (!Clean) {
			int prevY = y - moveDir[dir].y;
			int prevX = x - moveDir[dir].x;
			if ((0 <= prevY && prevY < N && 0 <= prevX && prevX < M) && map[prevY][prevX] != 1) {
				q.push({ {prevY, prevX}, dir });
			}
			else break;
		}
	}
	cout << cnt << "\n";
	return 0;
}
