#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
bool use[9];
int arr[9];
int n, MAX = 0;

void DFS(int idx) {
	if (idx == n) {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		MAX = max(MAX, sum);
	}
	for (int i = 0; i < n; i++) {
		if (use[i])continue;
		use[i] = true;
		v.push_back(arr[i]);
		DFS(idx + 1);
		use[i] = false;
		v.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DFS(0);
	cout << MAX;
	return 0;
}
