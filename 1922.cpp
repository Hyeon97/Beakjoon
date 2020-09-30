//ũ�罺Į
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int a, b, c;
bool V[1001];
vector< pair<int, pair<int, int> > >G;//����ġ, ����, ����
int parent[1001];//�θ�迭

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
	for (int i = 1; i <= N; i++)parent[i] = i;//�ʱⰩ ���� �ڱ��ڽ� ����
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		G.push_back({ c,{a,b} });
	}
	sort(G.begin(), G.end(), cmp);//����ġ ���� �������� ����
	int C = 0;
	for (int i = 0; i < M; i++) {
		int st = G[i].second.first;
		int ed = G[i].second.second;
		int cost = G[i].first;
		//�������� ������ �θ� ã��
		st = GetParent(st);
		ed = GetParent(ed);
		if (st == ed)continue;//������ �θ𰡰������ >> ������ ����Ǿ� ���� >> ����Ŭ �߻�
		C += cost;
		if (st < ed) {
			int temp = st;
			st = ed;
			ed = temp;
		}
		parent[ed] = st;//���������� �θ� ���������� ����
	}
	cout << C;


	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//����

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
int v[1001];
vector< pair<int, int> >G[1001];//����ġ, ����
priority_queue < pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>> > pq;
int parent[1001];//�θ�迭

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