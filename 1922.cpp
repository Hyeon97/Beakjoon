//크루스칼
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int a, b, c;
bool V[1001];
vector< pair<int, pair<int, int> > >G;//가중치, 시작, 종료
int parent[1001];//부모배열

bool cmp(const  pair<int, pair<int, int> >& A, const  pair<int, pair<int, int> >& B) {
	if (A.first < B.first)return true;
	return false;
}

int GetParent(int x) {
	if (x == parent[x])return x;
	return parent[x] = GetParent(parent[x]);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)parent[i] = i;//초기갑 세팅 자기자신 저장
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		G.push_back({ c,{a,b} });
	}
	sort(G.begin(), G.end(), cmp);//가중치 기준 오름차순 정렬
	int C = 0;
	for (int i = 0; i < M; i++) {
		int st = G[i].second.first;
		int ed = G[i].second.second;
		int cost = G[i].first;
		//시작점과 끝점의 부모를 찾음
		st = GetParent(st);
		ed = GetParent(ed);
		if (st == ed)continue;//두점이 부모가같은경우 >> 두점이 연결되어 있음 >> 사이클 발생
		C += cost;
		if (st < ed) {
			int temp = st;
			st = ed;
			ed = temp;
		}
		parent[ed] = st;//도작지점의 부모를 시작점으로 갱신
	}
	cout << C;


	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//프림

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
int v[1001];
vector< pair<int, int> >G[1001];//가중치, 종료
priority_queue < pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>> > pq;
int parent[1001];//부모배열

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	for (int i = 0, a, b, c; i < E; i++) {
		cin >> a >> b >> c;
		G[a].push_back({ c,b });
		G[b].push_back({ c,a });
	}
	pq.push({ 0,1 });
	int ans = 0, cnt = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (v[cur])continue;
		v[cur] = 1;
		ans += cost;
		if (++cnt == V)break;
		for (pair<int, int> temp : G[cur]) {
			if (v[temp.second])continue;
			pq.push(temp);
		}

	}
	cout << ans;
	return 0;
}