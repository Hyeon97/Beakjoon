#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	if (arr[0] != 1)cout << 1;//1g짜리 추가 없으면 1g을 잴수가 없음
	else {
		long long int sum = 0;//누적합
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if ( ( i+1<n && arr[i + 1] > sum+1 )) {//다음번 추의 무게가 현재 누적 무게+1g 보다 큰 경우 누적무게+1g을 표현할 수 없음
				cout << sum + 1;
				return 0;
			}
		}
		cout << sum + 1;
	}

	return 0;
}
