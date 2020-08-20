#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int>G[501];
bool list[501];
int member;

void DFS(int num) {
	//해당 노드의 친구들을 구함
	for (int i = 0; i < G[num].size(); i++) {
		list[G[num][i]] = true;
	}
	//해당 노드가 1번인 경우 1번의 친구들을 찾음
	if (num == 1) {
		for (int i = 0; i < G[num].size(); i++) {
			DFS(G[num][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	DFS(1);
	//자기 자신인 1을 제외하고 2부터 true인 친구들 숫자 카운팅
	for (int i = 2; i <= n; i++) {
		if (list[i])member++;
	}
	cout << member;

	return 0;
}