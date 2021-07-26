#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int n, m, p[1000001];

int find(int num) {
	if (p[num] == num)return num;
	return p[num] = find(p[num]);
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	p[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)p[i] = i;
	for (int i = 0, ty, a, b; i < m; i++) {
		cin >> ty >> a >> b;
		if (ty == 0) {
			uni(a, b);
		}
		else {
			find(a) == find(b) ? cout << "YES\n" : cout << "NO\n";
		}
	}

	return 0;
}
