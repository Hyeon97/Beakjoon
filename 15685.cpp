//구현
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef struct D {
	int y;
	int x;
};

D di[4] = { {0,1},{-1,0},{0,-1},{1,0} };//우 상 좌 하
int N, y, x, d, g;
int map[101][101];
vector<int>dir;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> x >> y >> d >> g;
		dir.push_back(d);
		for (int i = 1; i <= g; i++) {
			for (int j = dir.size() - 1; j >= 0; j--) {
				dir.push_back((dir[j] + 1) % 4);
			}
		}
		map[y][x] = 1;
		for (int j = 0; j < dir.size(); j++) {
			y += di[dir[j]].y;
			x += di[dir[j]].x;
			map[y][x] = 1;
		}
		dir.clear();
	}
	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x <100; x++) {
			if (map[y][x] && map[y + 1][x] && map[y][x + 1] && map[y + 1][x + 1])ans++;
		}
	}
	cout << ans;
	return 0;
}
