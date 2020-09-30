//프림
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
int v[100001];
vector< pair<int, int> >G[100001];//가중치, 종료
priority_queue < pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>> > pq;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0, a, b, c; i < E; i++) {
		cin >> a >> b >> c;
		G[a].push_back({ c,b });
		G[b].push_back({ c,a });
	}
	pq.push({ 0,1 });
	int ans = 0, cnt = 0, max = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (v[cur])continue;
		v[cur] = 1;
		ans += cost;
		max = (cost > max) ? cost : max;
		if (++cnt == V)break;
		for (pair<int, int> temp : G[cur]) {
			if (v[temp.second])continue;
			pq.push(temp);
		}

	}
	cout << ans - max;
	return 0;
}