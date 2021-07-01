#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Dir {
	int y;
	int x;
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {//m 세로 n 가로
	Dir D[4] = { {0,1},{1,0},{0,-1},{-1,0} };
	bool v[101][101];
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			v[y][x] = false;
		}
	}
	int max_size=0, cnt=0;
	vector<int> answer;
	queue<pair<int, int>>q;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (picture[y][x] && !v[y][x]) {
				cnt++;
				q.push({ y,x });
				int t_size = 0;
				while (!q.empty()) {
					int X = q.front().second;
					int Y = q.front().first;
					q.pop();
					//t_size++;
					if (v[Y][X])continue;
					v[Y][X] = true;
					t_size++;
					for (int i = 0; i < 4; i++) {
						int nx = X + D[i].x;
						int ny = Y + D[i].y;
						if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[ny][nx] || picture[ny][nx] != picture[y][x])continue;
						q.push({ ny,nx });
						//t_size++;
					}
				}
				if (max_size < t_size)max_size = t_size;
			}
		}
	}
	answer.push_back(cnt);
	answer.push_back(max_size);
    return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution(6, 4, { {1,1,1,0},{1,1,1,0},{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1}});
	return 0;
}