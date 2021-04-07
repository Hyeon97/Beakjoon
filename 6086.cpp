//네트워크 플로우(최대유량)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, ST, ED, val;
char st, ed;
int F[52][52];//현재 흐르고 있는 용량
int C[52][52];//간선의 총 용량

vector<int>adj[52];//각 정점의 간선 저장

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> st >> ed >> val;
		if ('A' <= st && st <= 'Z') ST = st - 'A';
		else ST = st - 'a' + 26;

		if ('A' <= ed && ed <= 'Z')ED = ed - 'A';
		else ED = ed - 'a' + 26;

		C[ST][ED] += val;
		C[ED][ST] += val;
		//간선추가
		adj[ST].push_back(ED);
		adj[ED].push_back(ST);
	}
	
	int TotalFlow = 0, S = 0, T = 'Z' - 'A';//S == source, T == sink
	
	while (1) {
		int prev[52];//탐색 경로 저장용
		for (int i = 0; i < 52; i++)prev[i] = -1;
		queue<int>q;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {

				int next = adj[cur][i];

				if (prev[next] != -1)continue;//방문한건 지나침

				if (C[cur][next] - F[cur][next] > 0) {//해당 간선의 총 옹량 - 현재 해당간선에 흐르는 용량 >0 >> 아직 더 흐를수 있음
					q.push(next);
					prev[next] = cur;
					if (next == T)break;//현재 위치기준 다음 노드가 도착지점인 경우 종료
				}
			}
		}
		if (prev[T] == -1)break;//도착지점의 경로가 없는경우 >> 유량 갱신할 필요 없음

		int flow = 987654321;
		//경로를 타고가면서 제일 작은 유량을 구해줌
		for (int i = T; i != S; i = prev[i]) {
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}

		for (int i = T; i != S; i = prev[i]) {
			F[prev[i]][i] += flow;//순방향으론 최소 유량만큼 +
			F[i][prev[i]] -= flow;//역방향으로 총 흐를수 있는 유량 - 현재 흐르는 유량
		}
		TotalFlow += flow;

	}
	cout << TotalFlow << '\n';
	return 0;
}