#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

//int g[20001][20001];
vector<pair<int, int>>g[20001];
int v, e, k;
int dist[20001];
bool vi[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e >> k;
	int a, b, c;
	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}
	dist[k] = 0;//시작정점은 0으로
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ c,b });//가중치, 정점순으로 넣기
	}
	pq.push({ 0,k });//비용,시작정점
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (vi[here])continue;
		vi[here] = 1;
		dist[here] = cost;
		for (pair<int, int> next : g[here]) {
			if (vi[next.second])continue;
			next.first += cost;
			pq.push(next);
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}
