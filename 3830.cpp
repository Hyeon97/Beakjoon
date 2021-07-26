#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

int n, m, a, b, we;
char ty;
int p[100001];
ll w[100001];

int find(int num) {
	if (p[num] == num)return num;
	//�θ�ã�ư��鼭 ����ġ ����
	int P = find(p[num]);
	w[num] += w[p[num]];
	return p[num] = P;
}

void uni(int a, int b, int W) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb)return;//�θ����� ����
	p[pb] = pa;
	//�� �θ��� ����(a) + �߰��� ���� - ����b ����
	w[pb] = w[a] + W - w[b];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			w[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			cin >> ty;
			if (ty == '!') {
				//b�� a���� ���ſ�
				cin >> a >> b >> we;
				uni(a, b, we);
			}
			else {
				cin >> a >> b;
				if (find(a) != find(b))cout << "UNKNOWN\n";
				else {
					cout << w[b] - w[a] << '\n';
				}
			}
		}
	}

	return 0;
}