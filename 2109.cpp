#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
pair <int, int >arr[10001];
priority_queue<int>pq;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {//날자 큰순으로 정렬
	return a.first > b.first;
}

//보석도둑 문제와 유사
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int day = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].second >> arr[i].first;
		day = arr[i].first > day ? arr[i].first : day;
	}
	sort(arr,arr+N, cmp);
	int sum = 0, idx=0;
	for (int i = day; i >= 1; i--) {
		while (idx < N && i <= arr[idx].first) {
			pq.push(arr[idx++].second);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	
	cout << sum;
	return 0;
}

