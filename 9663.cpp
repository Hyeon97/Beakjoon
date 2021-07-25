#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int map[15];

bool ch(int num) {
	for (int i = 0; i < num; i++) {
		if (map[i] == map[num] || abs(map[num] - map[i]) == (num - i))return false;
	}
	return true;
}

void NQ(int cnt) {
	if (cnt == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		map[cnt] = i;
		if (ch(cnt))NQ(cnt + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	NQ(0);
	cout << ans;
	return 0;
}
