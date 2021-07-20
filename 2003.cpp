#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int>arr;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int st = 0, ed = 0, cnt=0;
	long long sum = 0;
	for (int i = 0, temp; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	while(st<=ed && ed<=N) {
		if (sum == M)cnt++;
		if (sum < M)sum += arr[ed++];
		else {
			sum -= arr[st++];
			if (sum == M) {
				cnt++;
				sum -= arr[st++];
				if (st > ed) {
					int temp = st;
					st = ed;
					ed = temp;
				}
			}
		}
		
	}
	cout << cnt;
	return 0;
}

