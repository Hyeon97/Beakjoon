#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

int n, m;
vector<int>v[32001];
queue<int>q;
int arr[32001];
void BFS() {
	for (int i = 1; i <= n; i++) {
		//값이 0인경우 >> 해당 그룹에서 제일 앞
		if (!arr[i])q.push(i);
	}
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int next : v[temp]) {
			arr[next]--;
			if (!arr[next])q.push(next);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	BFS();
	return 0;
}