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
	for (int i = 1; i <= n; i++) {//전체 탐색 반복횟수
		for (int j = 1; j <= n; j++) {//각 정점(출발지)
			for (auto next : g[j]) {//각 정점(목적지)
				//해당 정점으로 가는 길이 존재 && 해당정점의 값보다 현재 값이 더 작은경우
				if (dist[j] != INF && dist[next.first] > next.second + dist[j]) {
					dist[next.first] = next.second + dist[j];
					//i가 끝까지 왔는데 여기 조건에 걸리는 경우 >> 음수사이클 존재 >> 무한번 돌게됨
					//원래는 n-1번 순환하면서 끝나야 정상
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