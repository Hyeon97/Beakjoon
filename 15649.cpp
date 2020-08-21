#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool use[9];
vector<int>v;

void DFS(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (use[i])continue;
		use[i] = true;
		v.push_back(i);
		DFS(cnt + 1);
		use[i] = false;
		v.pop_back();

	}
}

int main() {
	cin >> n >> m;

	DFS(0);

	return 0;
}