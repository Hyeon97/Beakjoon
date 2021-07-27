#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAX 100001
typedef long long ll;
using namespace std;

vector<int>g[MAX];//그래프용
int ac[20][MAX];//조상파악용
int d[MAX];
int max_level = (int)floor(log2(MAX));
int n, m;

void getTree(int here, int parent) {
	d[here] = d[parent] + 1;
	ac[0][here] = parent;
	for (int i = 1; i <= max_level; i++) {
		ac[i][here] = ac[i - 1][ac[i - 1][here]];
	}
	for (int next : g[here]) {
		if (next != parent)getTree(next, here);
	}
}

int FIND(int a, int b) {
	if (d[a] != d[b]) {
		if (d[a] > d[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		for (int i = max_level; i >= 0; i--) {
			if (d[a] <= d[ac[i][b]])b = ac[i][b];
		}
	}
	int lca = a;
	if (a != b) {
		for (int i = max_level; i >= 0; i--) {
			if (ac[i][a] != ac[i][b]) {
				a = ac[i][a];
				b = ac[i][b];
			}
			lca = ac[i][a];
		}
	}
	return lca;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {//그래프 제작
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//트리 제작
	d[0] = -1;

	getTree(1, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << FIND(a, b) << "\n";
	}
	return 0;
}