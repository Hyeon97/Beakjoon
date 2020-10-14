#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
long long N[1000001];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long Min, Max;
	cin >> Min >> Max;
	int pidx = 0, cnt = 0;

	for (long long i = 2; i * i <= Max; i++) {
		long long temp = Min / (i * i);
		if (Min % (i * i) != 0)temp++;
		while (temp * (i * i) <= Max) {
			N[temp * (i * i) - Min] = 1;
			temp++;
		}
	}
	for (int i = 0; i <= Max - Min; i++) {
		if (N[i] == 0)cnt++;
	}
	cout << cnt;

	return 0;
}