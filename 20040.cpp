#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int P[500001];
int N, M;

int FIND(int x) {//부모찾는 함수
	if (x == P[x])return x;
	else {
		int temp = FIND(P[x]);
		P[x] = temp;
		return temp;
	}
}

bool U(int x, int y) {//부모비교 함수
	x = FIND(x);
	y = FIND(y);
	if (x == y)return true;
	P[y] = x;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	//부모 초기화
	for (int i = 0; i < N; i++) {
		P[i] = i;
	}

	//bool OUT = false;
	for (int i = 0, s,e; i < M; i++) {
		cin >> s >> e;
		if (s > e) {
			int temp = s;
			s = e;
			e = temp;
		}
		if (U(s, e)) {
			cout << i+1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}