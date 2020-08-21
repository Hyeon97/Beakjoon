#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[65][65];

void DFS(int n, int y, int x) {
	int temp = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (map[i][j])temp++;
		}
	}
	if (temp == 0)cout << 0;
	else if (temp == n * n)cout << 1;
	else {
		cout << '(';
		DFS(n / 2, y, x);
		DFS(n / 2, y, x + n / 2);
		DFS(n / 2, y + n / 2, x);
		DFS(n / 2, y + n / 2, x + n / 2);
		cout << ')';
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	DFS(n, 0, 0);
	return 0;
}