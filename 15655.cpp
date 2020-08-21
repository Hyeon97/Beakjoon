#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int out[9];
bool v[9];

void DFS(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << out[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < n; i++) {
		if (v[i])continue;
		v[i] = true;
		out[cnt] = arr[i];
		DFS(cnt + 1, i + 1);
		v[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	DFS(0, 0);

	return 0;
}