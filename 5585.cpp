#include <iostream>
#include <algorithm>

using namespace std;

int N,ans;
int arr[6] = { 500,100,50,10,5,1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	N = 1000 - N;
	for (int i = 0; i < 6; i++) {
		if (arr[i] > N)continue;
		ans += N / arr[i];
		N %= arr[i];
	}
	cout << ans;
	return 0;
}
