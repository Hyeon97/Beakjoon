#include <iostream>

using namespace std;

int n, s;
int arr[21];
bool v[21];
int cnt;

void DFS(int idx, int sum) {
	if (idx == n)return;//������ Ž���� ����
	if (sum + arr[idx] == s)cnt++;//���Ǹ����� ++

	DFS(idx + 1, sum);
	DFS(idx + 1, sum + arr[idx]);
}

int main() {

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	DFS(0, 0);
	cout << cnt;
	return 0;
}