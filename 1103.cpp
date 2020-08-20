#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[51][51], dp[301][301];
bool v[51][51];
int n, m;
//오른쪽 아래 왼쪽 위
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int DFS(int Y, int X) {
	//범위 초과 또는 구멍인경우엔 0리턴
	if (X < 0 || X >= m || Y < 0 || Y >= n || map[Y][X] == 0)return 0;
	//순회도중 순회경로에서 이미 방문한 곳 또 도착시 사이클이 존재 한다고 판단 >> 무한반복 가능 >> -1 출력후 강제종료
	if (v[Y][X]) {
		cout << -1;
		exit(0);
	}
	//현 좌표의 dp값이 0이 아닌경우 값 리턴
	if (dp[Y][X] != -1)return dp[Y][X];
	//방문 체크
	v[Y][X] = true;
	dp[Y][X] = 0;
	for (int i = 0; i < 4; i++) {
		int x = X + map[Y][X] * dx[i];
		int y = Y + map[Y][X] * dy[i];
		dp[Y][X] = (dp[Y][X] > DFS(y, x) + 1) ? dp[Y][X] : DFS(y, x) + 1;
	}
	v[Y][X] = false;
	return dp[Y][X];
}

int main() {
	cin >> n >> m;
	char temp;
	memset(dp, -1, sizeof(dp));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> temp;
			if (temp != 'H')map[y][x] = temp - '0';
			else map[y][x] = 0;
		}
	}
	cout << DFS(0, 0);


	return 0;
}