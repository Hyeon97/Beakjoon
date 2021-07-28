#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define INF 987654321
using namespace std;

int W, H, G, E, y, x, y2, x2, w;
vector<pair<int, int>>edge[910];
int map[31][31];
ll dist[910];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		//초기화
		for (int i = 0; i < 910; i++) {
			edge[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				map[i][j] = 0;
			}
		}
		//시작
		cin >> G;
		for (int i = 0; i < G; i++) {//무덤 좌표
			cin >> x >> y;
			map[y][x] = 1;
		}
		cin >> E;
		for (int i = 0; i < E; i++) {//귀신 구멍 좌표
			cin >> x >> y >> x2 >> y2 >> w;
			map[y][x] = 2;
			edge[y * W + x + 1].push_back({ y2 * W + x2 + 1,w });
		}
		//무덤 경로 채워주기
		for (int x = 0; x < W; x++) {
			for (int y = 0; y < H; y++) {
				//무덤인경우 못지나감, 구멍인경우 무조건 정해진 경로로만 이동가능, 도착지점에선 안움직임
				if (map[y][x] || (y == H - 1 && x == W - 1))continue;
				//4방향
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (0 <= nx && nx < W && 0 <= ny && ny < H && map[ny][nx] != 1) {
						edge[y * W + x + 1].push_back({ ny * W + nx + 1, 1 });
					}
				}
			}
		}

		dist[1] = 0;
		bool cycle = false;
		for (int i = 0; i < W * H; i++) {//전체 탐색 반복횟수
			for (int j = 1; j < W * H; j++) {//각 정점(출발지)
				if (dist[j] == INF)continue;
				for (auto next : edge[j]) {//각 정점(목적지)
					//해당 정점으로 가는 길이 존재 && 해당정점의 값보다 현재 값이 더 작은경우
					if (dist[next.first] > next.second + dist[j]) {
						dist[next.first] = next.second + dist[j];
						//i가 끝까지 왔는데 여기 조건에 걸리는 경우 >> 음수사이클 존재 >> 무한번 돌게됨
						//원래는 n-1번 순환하면서 끝나야 정상
						if (i == W * H-1)cycle = true;
					}
				}
			}
		}
		if (cycle)cout << "Never\n";
		else {
			if (dist[W*H] == INF)cout << "Impossible\n";
			else cout << dist[W*H] << '\n';
		}
	}

	return 0;
}