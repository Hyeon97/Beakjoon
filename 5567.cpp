#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int>G[501];
bool list[501];
int member;

void DFS(int num) {
	//�ش� ����� ģ������ ����
	for (int i = 0; i < G[num].size(); i++) {
		list[G[num][i]] = true;
	}
	//�ش� ��尡 1���� ��� 1���� ģ������ ã��
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
	//�ڱ� �ڽ��� 1�� �����ϰ� 2���� true�� ģ���� ���� ī����
	for (int i = 2; i <= n; i++) {
		if (list[i])member++;
	}
	cout << member;

	return 0;
}