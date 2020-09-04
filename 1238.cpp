#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int N, M, X, MAX;
int dist[1001];
bool v[1001];
vector< pair <int, int> >G[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;//출발, 도착, 소요시간
		G[a].push_back({ c,b });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[j] = INF; v[j] = false;
		}
		//각 i에서 파티장까지
		dist[i] = 0;
		pq.push({ 0,i });
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (v[here])continue;
			dist[here] = cost;
			v[here] = 1;
			for (auto next : G[here]) {
				if (v[next.second])continue;
				next.first += cost;
				pq.push(next);
			}
		}
		int temp = dist[X];
		for (int j = 1; j <= N; j++) {
			dist[j] = INF; v[j] = false;
		}
		//파티장에서 i정점까지
		dist[X] = 0;
		pq.push({ 0,X });
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (v[here])continue;
			dist[here] = cost;
			v[here] = 1;
			for (auto next : G[here]) {
				if (v[next.second])continue;
				next.first += cost;
				pq.push(next);
			}
		}
		MAX = (MAX > dist[i]+temp) ? MAX : dist[i]+temp;
	}
	cout << MAX;
	return 0;
}