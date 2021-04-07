//네트워크 플로우(최대유량)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int P, N, ST, ED;
char st, ed;
int F[401][401];//현재 흐르고 있는 용량
int C[401][401];//간선의 총 용량

vector<int>adj[401];//각 정점의 간선 저장

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	for (int i = 0; i < P; i++) {
		cin >> ST >> ED;
		adj[ST].push_back(ED);
		adj[ED].push_back(ST);

		C[ST][ED] += 1;
		//C[ED][ST] += 1;
	}
	int Total_Flow = 0, S = 1, E = 2;

	while (1) {
		queue<int>q;
		q.push(S);
		int prev[401];
		for (int i = 0; i < 401; i++)prev[i] = -1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				if (prev[next] != -1)continue;

				if (C[now][next] - F[now][next] > 0) {
					q.push(next);
					prev[next] = now;
					if (next == E)break;//현재 위치기준 다음 노드가 도착지점인 경우 종료
				}
			}
		}
		if (prev[E] == -1)break;

		int flow = 987654321;
		//경로를 타고가면서 제일 작은 유량을 구해줌
		for (int i = E; i != S; i = prev[i]) {
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}

		for (int i = E; i != S; i = prev[i]) {
			F[prev[i]][i] += flow;//순방향으론 최소 유량만큼 +
			F[i][prev[i]] -= flow;//역방향으로 총 흐를수 있는 유량 - 현재 흐르는 유량
		}
		Total_Flow += flow;
	}
	cout << Total_Flow;

	return 0;
}