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
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;//보석정보
	for (int i = 0; i < k; i++) cin >> b[i];//가방용량
	//보석, 가방 정렬
	sort(p, p + n);
	sort(b, b + k);

	int j = 0;
	ll out = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && p[j].first <= b[i]) {//인덱스가 전채 보석수 보다 작으면서 보석무게가 가방무게보다 같거나 작은경우
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
