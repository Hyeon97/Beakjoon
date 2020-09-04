#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, M;
vector<pair<int, int>>g[1001];
int dist[1001];
bool vi[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;//��� , ����, ���
		g[a].push_back({c,b});//���, ����
	}
	int st, ed;
	cin >> st >> ed;
	dist[st] = 0;
	pq.push({0,st});//�������� ���� �ֱ�
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (vi[here])continue;
		vi[here] = 1;
		dist[here] = cost;
		for (pair<int, int> next : g[here]) {
			if (vi[next.second])continue;
			next.first += cost;//�湮���� ������ ��� ����߰�
			pq.push(next);
		}
	}
	cout << dist[ed];

	return 0;
}
