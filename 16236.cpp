#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define i_ii pair<int, pair<int,int>>
#define ii pair<int,int>

using namespace std;

typedef struct mi {
	int dist;
	int y;
	int x;
	int size;
};

typedef struct M {
	int dist;
	int y;
	int x;
};

int n, cnt;
int map[21][21];

//우 하 좌 상
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
pair<int, int>me;
int Size = 2;
int eat = 0;
queue<M>q;
vector<mi>V;

bool cmp(mi a, mi b) {
	if (a.dist < b.dist)return true;
	else if(a.dist==b.dist){
		if (a.y < b.y)return true;
		else if (a.y == b.y) {
			if (a.x < b.x)return true;
		}
	}
	return false;
}

void BFS() {
	while (1) {
		bool vi[21][21] = { 0, };
		q.push({ 0,me.first,me.second });
		while (!q.empty()) {
			M temp = q.front();
			q.pop();
			int x = temp.x;
			int y = temp.y;
			int dist = temp.dist;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1 || map[ny][nx]>Size || vi[ny][nx])continue;//범위 밖 또는 나보다 큰물고기 칸으론 못감
				q.push({ dist + 1,ny,nx });
				vi[ny][nx] = true;
				if (map[ny][nx] >0 && map[ny][nx] < Size) {//현재칸의 물고기 크기가 나보다 작은경우 먹을 수 있음
					V.push_back({ dist+1,ny,nx,map[ny][nx] });//현재 아기상어와의 거리
				}
			}
		}
		if (V.empty())break;
		//정렬 우선순위 y값 작은순 >> x값 작은순
		sort(V.begin(), V.end(), cmp);
		//제일 맨앞 먹이 먹음
		cnt += V[0].dist;
		me = { V[0].y,V[0].x };//내위치 > 먹이의 위치로 이동
		map[V[0].y][V[0].x] = 0;//해당칸 비워줌
		//먹이 먹은수 증가
		eat++;
		if (eat == Size) {//몸집크기만큼 먹이 먹은경우
			Size++;//몸집 증가
			eat = 0;//먹은 숫자 초기화
		}
		V.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)me = { i,j }, map[i][j] = 0;

		}
	}
	BFS();
	cout << cnt;

	return 0;
}
