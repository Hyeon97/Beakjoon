#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, E;
vector<pair<int, int>>g[801];
int dist[801];
bool vi[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

void D(int x) {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF; vi[i] = 0;
	}
	dist[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (vi[here])continue;
		vi[here] = 1;
		dist[here] = cost;
		for (pair< int, int> next : g[here]) {
			if (vi[next.second])continue;
			next.first += cost;
			pq.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ c,b });
		g[b].push_back({ c,a });
	}
	int v1, v2;
	cin >> v1 >> v2;
	int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
	D(1);//시작정점부터 필수 정점 2개까지의 거리
	d1 = dist[v1];
	d2 = dist[v2];
	if (d1 >= INF && d2 >= INF) {
		cout << -1;
		return 0;
	}
	D(N);//도착정점부터 필수 정점 2개까지의 거리
	d3 = dist[v1];
	d4 = dist[v2];
	if (d3 >= INF && d4 >= INF) {
		cout << -1;
		return 0;
	}
	D(v1);//D(v2)도 상관없음 둘사이의 거리만 구하면됨
	d5 = dist[v2];//D(v2) 인경우엔 d5=dist[v1];
	if (d5 >= INF) {
		cout << -1;
		return 0;
	}
	(d1 + d4) > (d2 + d3) ? cout << d2 + d3 + d5 : cout << d1 + d4 + d5;
	return 0;
}
