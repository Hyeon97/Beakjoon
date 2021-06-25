#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct CO {
	int y;
	int x;
};

int N, L, R;
int map[51][51];
bool vi[51][51];
bool ch = false;
vector<CO>v;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	int ans = 0;
	while (1) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				vi[y][x] = false;
			}
		}
		//BFS탐색을 통해 국경을 여는 모든나라 찾기
		int sum = 0;//국경 개방한 나라의 인구수 총합
		ch = false;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!vi[y][x]) {//해당정점에서 국경열리는 모든나라 탐색
					queue<CO>q;
					//먼저 해당 나라에서 4방향 탐색하여 조건에 부합하는 나라 넣어줌
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N || vi[ny][nx] || !(L <= abs(map[ny][nx] - map[y][x]) && abs(map[ny][nx] - map[y][x]) <= R))continue;
						q.push({ ny,nx });
					}
					if (!q.empty()) {
						sum += map[y][x];
						vi[y][x] = true;
						v.push_back({ y,x });
					}
					while (!q.empty()) {
						CO temp = q.front();
						q.pop();
						if (vi[temp.y][temp.x])continue;
						vi[temp.y][temp.x] = true;
						v.push_back({ temp.y,temp.x });
						sum += map[temp.y][temp.x];
						for (int i = 0; i < 4; i++) {
							int nx = temp.x + dx[i];
							int ny = temp.y + dy[i];
							if (nx<0 || ny<0 || nx>=N || ny>=N || vi[ny][nx] || !(L <= abs(map[ny][nx] - map[temp.y][temp.x]) && abs(map[ny][nx] - map[temp.y][temp.x]) <= R))continue;
							q.push({ny,nx});
						}
					}
					if (v.size()) {
						ch = true;
						int avg = sum / v.size();
						for (int i = 0; i < v.size(); i++) {
							map[v[i].y][v[i].x] = avg;
						}
						sum = 0;
						v.clear();
					}
				}
			}
		}
		//if (!v.size())break;
		/*int avg = sum / v.size();
		for (int i = 0; i < v.size(); i++) {
			map[v[i].y][v[i].x] = avg;
		}*/
		if (!ch)break;
		ans++;
		v.clear();
	}
	cout << ans;

	return 0;
}
