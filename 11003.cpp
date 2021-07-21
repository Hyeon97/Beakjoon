//전체 배열입력받음
//덱을 이용 해당구간에서 제일 작은 숫자만을 남기면서 탐색

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define ll long long

using namespace std;


int N, L;
vector<long long>arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0, temp; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	deque<pair<ll, ll>>dq;//원래순서, 값
	for (int i = 0; i < N; i++) {
		//범위 : i - 1 + L ~ i
		//범위 밖에 있는 아래쪽 숫자들 제거
		if (!dq.empty() && dq.front().second <= i - L)dq.pop_front();
		//덱에는 제일 작은 숫자만 남겨둠
		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();
		//현재 값 넣어줌
		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
	}

	return 0;
}
