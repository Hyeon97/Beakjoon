#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int N;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	
	for (int i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			cout << i << '\n';
			N /= i;
		}
	}
	if (N > 1)cout << N;

	return 0;
}
