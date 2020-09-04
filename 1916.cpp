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
		cin >> a >> b >> c;//출발 , 도착, 비용
		g[a].push_back({c,b});//비용, 도착
	}
	int st, ed;
	cin >> st >> ed;
	dist[st] = 0;
	pq.push({0,st});//시작지점 정보 넣기
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (vi[here])continue;
		vi[here] = 1;
		dist[here] = cost;
		for (pair<int, int> next : g[here]) {
			if (vi[next.second])continue;
			next.first += cost;//방문안한 정점인 경우 비용추가
			pq.push(next);
		}
	}
	cout << dist[ed];

	return 0;
}
