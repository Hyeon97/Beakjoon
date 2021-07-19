#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
char arr[52][52];
int v[52][52];
queue<pair<int, int>>W;//침수지점 좌표
queue<pair<int, int>>S;//비버 움직이는 좌표
int T, Y, X;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int BFS() {
	int count = 0;
	while (!S.empty()) {
		//물 확산
		int ws = W.size();
		for (int i = 0; i < ws; i++) {
			int y = W.front().first;
			int x = W.front().second;
			W.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < X && 0 <= ny && ny < Y && arr[ny][nx] == '.') {
					arr[ny][nx] = '*';
					W.push({ ny,nx });
				}
			}
		}
		//비버 움직이기
		int qs = S.size();
		for (int i = 0; i < qs; i++) {
			int y = S.front().first;
			int x = S.front().second;
			S.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < X && 0 <= ny && ny < Y && (arr[ny][nx] == '.' || arr[ny][nx] == 'D')) {
					if (arr[ny][nx] == 'D')return count + 1;
					else {
						v[ny][nx] = true;
						S.push({ ny,nx });
					}
				}
			}
		}
		count++;
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {//비버 위치
				S.push({ i,j });
			}
			if (arr[i][j] == '*')W.push({ i,j });
		}
	}
	int out = BFS();
	out == -1 ? cout << "KAKTUS\n" : cout << out << "\n";
	return 0;
}
