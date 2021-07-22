#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int arr[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}
	int count = 0;
	for (int i = 2; i*i <= n; i++) {
		if (arr[i]) {
			for (int j = i+i; j <= n; j += i) {
				if (arr[j]) {
					arr[j] = 0;
					count++;
					if (count == k) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}
