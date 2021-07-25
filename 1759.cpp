#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char ans[16], arr[16];

void Back(int idx, int ja, int mo) {
	if (ja + mo == L) {
		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < L; i++)cout << ans[i];
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		ans[ja+mo] = arr[i];
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')Back(i + 1, ja, mo + 1);
		else Back(i + 1, ja + 1, mo);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++)cin >> arr[i];
	sort(arr, arr + C);
	Back(0,0,0);
	return 0;
}
