#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int n;
int dist[126][126];
bool v[126][126];
int g[126][126];
priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >pq;
int num = 1;
void BFS() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
			v[i][j] = 0;
		}
	}
	pq.push({ 0,{0,0} });
	v[0][0] = 1;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			int tempcost = cost + g[X][Y];
			if (0 <= X && X < n && 0 <= Y && y < n && !v[X][Y] && dist[X][Y]>tempcost) {
				v[X][Y] = 1;
				dist[X][Y] = tempcost;
				pq.push({ tempcost,{X,Y} });
			}
		}
	}
	cout << "Problem " << num++ << ": " << g[0][0] + dist[n - 1][n - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n;
		if (!n)return 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
		}
		BFS();
	}
	return 0;
}