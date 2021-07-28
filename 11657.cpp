#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define INF 987654321
using namespace std;

int n, m, a, b, c;
vector<pair<int, int>>g[501];
ll dist[501];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++)dist[i] = INF;
	dist[1] = 0;
	bool cycle = false;
	for (int i = 1; i <= n; i++) {//��ü Ž�� �ݺ�Ƚ��
		for (int j = 1; j <= n; j++) {//�� ����(�����)
			for (auto next : g[j]) {//�� ����(������)
				//�ش� �������� ���� ���� ���� && �ش������� ������ ���� ���� �� �������
				if (dist[j] != INF && dist[next.first] > next.second + dist[j]) {
					dist[next.first] = next.second + dist[j];
					//i�� ������ �Դµ� ���� ���ǿ� �ɸ��� ��� >> ��������Ŭ ���� >> ���ѹ� ���Ե�
					//������ n-1�� ��ȯ�ϸ鼭 ������ ����
					if (i == n)cycle = true;
				}
			}
		}
	}
	if (cycle)cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)cout << "-1\n";
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}