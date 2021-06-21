#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int  count = 0;
	int temp = arr[0];
	for (int i = 0; i < N; i++) {
		if (arr[i] <= L - 1 + temp) continue;//고장지점 ~ 테이프길이 -1 만큼 한번에 수리가능
		temp = arr[i];
		count++;

	}
	cout << count + 1;

	return 0;
}
