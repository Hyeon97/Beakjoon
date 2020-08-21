#include <iostream>

using namespace std;

int n, m;
int arr[8];


void DFS(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++) {
		arr[cnt] = i;
		DFS(cnt + 1, i + 1);
	}
}

int main() {
	cin >> n >> m;

	DFS(0, 1);

	return 0;
}