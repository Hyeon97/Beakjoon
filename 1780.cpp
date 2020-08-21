#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[2200][2200];
int Minus, zero, Plus;

void DFS(int n, int y, int x) {
	bool mo = 0, z = 0, o = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (map[i][j] == -1)mo = true;
			else if (map[i][j] == 0)z = true;
			else o = true;

			if (mo && z || mo && o || z && o)break;
		}
		if (mo && z || mo && o || z && o)break;
	}
	if (mo && !z && !o) {
		Minus++;
	}
	else if (!mo && z && !o) {
		zero++;
	}
	else if (!mo && !z && o) {
		Plus++;
	}
	else {
		DFS(n / 3, y, x);
		DFS(n / 3, y, x + n / 3);
		DFS(n / 3, y, x + (n / 3) * 2);
		DFS(n / 3, y + n / 3, x);
		DFS(n / 3, y + n / 3, x + n / 3);
		DFS(n / 3, y + n / 3, x + (n / 3) * 2);
		DFS(n / 3, y + (n / 3) * 2, x);
		DFS(n / 3, y + (n / 3) * 2, x + n / 3);
		DFS(n / 3, y + (n / 3) * 2, x + (n / 3) * 2);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	DFS(n, 0, 0);
	cout << Minus << '\n' << zero << '\n' << Plus;
	return 0;
}