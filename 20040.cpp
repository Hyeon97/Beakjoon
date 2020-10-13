#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int P[500001];
int N, M;

int FIND(int x) {//�θ�ã�� �Լ�
	if (x == P[x])return x;
	else {
		int temp = FIND(P[x]);
		P[x] = temp;
		return temp;
	}
}

bool U(int x, int y) {//�θ�� �Լ�
	x = FIND(x);
	y = FIND(y);
	if (x == y)return true;
	P[y] = x;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	//�θ� �ʱ�ȭ
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