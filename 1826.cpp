#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, L, P, D;
priority_queue< int >pq;
pair <int, int> arr[10001];//거리, 연료량
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	cin >> L >> P;
	sort(arr, arr + N);
	int idx = 0;
	while (P < L) {
		while (arr[idx].first<=P) {//지금 가지고 있는 연료로 갈수있는 모든 주유소 저장
			if (idx == N)break;
			pq.push(arr[idx++].second);//해당주유소의 기름 양 저장
		}
		if (!pq.size())break;//주우소에 도착못하는 경우
		D++;//주유소 방문횟수 ++
		P += pq.top();//연료 추가
		pq.pop();
	}
	P < L ? cout << -1 : cout << D;

	return 0;
}
