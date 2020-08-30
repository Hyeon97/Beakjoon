#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

int n, k;
int b[300001];
pair<int, int>p[300001];
priority_queue<int>pq;
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;//��������
	for (int i = 0; i < k; i++) cin >> b[i];//����뷮
	//����, ���� ����
	sort(p, p + n);
	sort(b, b + k);

	int j = 0;
	ll out = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && p[j].first <= b[i]) {//�ε����� ��ä ������ ���� �����鼭 �������԰� ���湫�Ժ��� ���ų� �������
			pq.push(p[j++].second);
		}
		if (!pq.empty()) {
			out += pq.top();
			pq.pop();
		}
	}
	cout << out;

	return 0;
}
