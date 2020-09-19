#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int max = 0;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		max = (max > arr[i] * (N-i)) ? max : arr[i] * (N-i);
	}
	cout << max;
	
	return 0;
}
