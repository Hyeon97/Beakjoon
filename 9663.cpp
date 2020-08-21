#include <iostream>
#include <algorithm>

using namespace std;

int map[15];
int n, result = 0;

bool check(int num) {
	for (int i = 0; i < num; i++) {
		if (map[i] == map[num] || abs(map[num] - map[i]) == (num - i))return false;
	}
	return true;
}

void N_Qeen(int num) {
	if (num == n)result += 1;
	else {
		for (int i = 0; i < n; i++) {
			map[num] = i;
			if (check(num))N_Qeen(num + 1);
		}
	}
}

int main() {
	cin >> n;
	N_Qeen(0);
	cout << result;
	return 0;
}