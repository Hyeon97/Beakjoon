#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10][10];
vector<pair<int, int>>v;

bool ch1(int temp, int num) {//세로 체크
	for (int i = 0; i < 9; i++) {
		if (arr[i][temp] == num)return false;
	}
	return true;
}
bool ch2(int temp, int num) {//가로 체크
	for (int i = 0; i < 9; i++) {
		if (arr[temp][i] == num)return false;
	}
	return true;
}
bool ch3(int x, int y, int num) {//3*3체크
	x = x / 3;
	y = y / 3;
	for (int X = x * 3; X < (x * 3) + 3; X++) {
		for (int Y = y * 3; Y < (y * 3) + 3; Y++) {
			if (arr[X][Y] == num)return false;
		}
	}
	return true;
}

void DFS(int idx) {
	if (idx == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	for (int num = 1; num <= 9; num++) {
		int x = v[idx].first;
		int y = v[idx].second;
		if (ch1(y, num) && ch2(x, num) && ch3(x, y, num)) {
			arr[x][y] = num;
			DFS(idx + 1);
			arr[x][y] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)v.push_back({ i,j });
		}
	}
	for (int num = 1; num <= 9; num++) {
		int x = v[0].first;
		int y = v[0].second;
		if (ch1(y, num) && ch2(x, num) && ch3(x, y, num)) {
			arr[x][y] = num;
			DFS(1);
			arr[x][y] = 0;
		}
	}

	return 0;
}