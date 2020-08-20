#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

int n, m;
int map[303][303];
//Å½»ö¼ø¼­ ¿À¸¥ÂÊ ¾Æ·¡ ¿ÞÂÊ À§
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int year;

bool v[303][303];

void BFS() {
	int copy[300][300]; //±âÁ¸ÀÇ ºù»ê º¹»ç

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			copy[y][x] = map[y][x];
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (copy[i][j]) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int TY = i + dy[k];
					int TX = j + dx[k];
					if (copy[TY][TX] == 0)cnt++;
				}
				map[i][j] = copy[i][j] - cnt;
				if (map[i][j] < 0)map[i][j] = 0;
			}
		}
	}
}

void DFS(int y, int x) {
	v[y][x] = true;
	//ÇØ´çÁÂÇ¥¿¡¼­ 4¹æÇâ Å½»ö
	for (int i = 0; i < 4; i++) {
		int TX = x + dx[i];
		int TY = y + dy[i];
		if (!v[TY][TX] && map[TY][TX] && 0 < TY && TY < n - 1 && 0 < TX && TX < m - 1) {
			DFS(TY, TX);
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		memset(v, false, sizeof(v));
		int cnt = 0;
		bool none = false;
		//ºù»ê °¹¼ö Å½»ö
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (map[i][j] && !v[i][j]) {
					cnt++;
					if (cnt == 2) {
						none = true;
						break;
					}
					DFS(i, j);
				}
			}

		}
		//if (none)break;
		if (none)break;

		if (cnt == 0) {
			year = 0;
			break;
		}
		//ºù»ê ³ì¾Æ³»¸²
		BFS();
		year++;
	}
	cout << year;

	return 0;
}