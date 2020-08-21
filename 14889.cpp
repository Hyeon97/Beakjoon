#include <iostream>
#include <algorithm>

using namespace std;

int arr[21][21];
int n;
int result = 999999999;
bool v[21];
void DFS(int cnt, int idx) {
	if (idx == n + 1)return;
	if (cnt == n / 2) {
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i] && v[j])start += arr[i][j];
				if (!v[i] && !v[j])link += arr[i][j];
			}
		}
		result = min(result, abs(start - link));
		return;
	}
	v[idx] = true;
	DFS(cnt + 1, idx + 1);
	v[idx] = false;
	DFS(cnt, idx + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	DFS(0, 1);
	cout << result;
	return 0;
}