#include <iostream>
#include <algorithm>

using namespace std;

int n, r, c, cnt;

void DFS(int n, int y, int x) {
	if (n == 2) {
		if (y == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y == r && x + 1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		return;

	}

	DFS(n / 2, y, x);
	DFS(n / 2, y, x + n / 2);
	DFS(n / 2, y + n / 2, x);
	DFS(n / 2, y + n / 2, x + n / 2);
}

int main() {

	cin >> n >> r >> c;
	DFS(1 << n, 0, 0);
	return 0;
}