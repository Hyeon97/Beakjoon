#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int map[101][101];//1 : 사과 2 : 뱀 위치
deque<pair<int, int>>snake;//덱의 길이 == 뱀의 길이, 덱 내부 좌표 == 뱀 몸통위치
vector<pair<int, int>>v;
//오 위 왼 아래
int dir = 0;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int N, K, L, ans;
char C;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0, x, y; i < K; i++) {
		cin >> y >> x;
		map[y][x] = 1;
	}

	cin >> L;
	for (int i = 0, num; i < L; i++) {
		cin >> num >> C;
		v.push_back({ num,C });
	}

	snake.push_back({ 1,1 });
	map[1][1] = 2;
	int cnt = 0;
	while (1) {
		ans++;
		//머리이동
		int nx = snake.front().second + dx[dir];
		int ny = snake.front().first + dy[dir];
		//머리의 이동위치가 map의 벽 또는 자신의 몸통과 부딫히는 경우 종료
		if (nx < 1 || nx > N || ny < 1 || ny > N || map[ny][nx] == 2) {
			cout << ans;
			return 0;
		}
		//움직일수 있는 경우
		else {//사과 없는경우
			if (map[ny][nx] == 0) {//사과 안먹은 경우 꼬리 절단
				map[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			//머리이동	
			map[ny][nx] = 2;
			//새로운 머리 좌표 추가
			snake.push_front({ ny,nx });
		}
		if (cnt<v.size() && ans == v[cnt].first) {
			//이동완료시 방향전환
			dir = v[cnt].second == 'L' ? (dir + 1) % 4 : (dir + 3) % 4;
			cnt++;
		}
	}
	cout << ans;

	return 0;
}
