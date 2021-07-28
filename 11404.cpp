#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long
#define INF 987654321
using namespace std;

int n, m, a, b, c;
int g[101][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}
	for (int via = 1; via <= n; via++) {//1번정점부터 n번 정점까지(시작정점)
		for (int from = 1; from <= n; from++) {//1번 정점부터 탐색 시작
			if (!g[from][via])continue;//현 위치값이 0인경우 넘기기
			for (int to = 1; to <= n; to++) {
				if (from == to || !g[via][to]) continue;
				if (g[from][to] > g[from][via] + g[via][to] || !g[from][to]) g[from][to] = g[from][via] + g[via][to];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] == INF ? cout << 0 << ' ' : cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}