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
	//직전에 사용한 숫자 저장
	int temp = -1;

	for (int i = idx; i < n; i++) {
		//비 내림차순 조건
		if (temp != arr[i]) {
			//v[i] = true;
			out[cnt] = arr[i];
			temp = arr[i];
			DFS(cnt + 1, i);
			//v[i] = false;
		}
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