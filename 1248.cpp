#include <iostream>
#include <algorithm>

using namespace std;

int N;
char S[10][10];
int temp[10];

bool Check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += temp[i];
		if (S[i][idx] == '-' && sum >= 0) return false;
		else if (S[i][idx] == '+' && sum <= 0)return false;
		else if (S[i][idx] == '0' && sum != 0)return false;
	}
	return true;
}

void Make(int idx) {
	if (idx == N) {
		//여기에 들어옴 == 모든조건에 성립 >> 출력후 종료
		for (int i = 0; i < N; i++) {
			cout << temp[i] << ' ';
		}
		exit(0);
	}
	for (int i = -10; i <= 10; i++) {
			temp[idx] = i;
			//실시간으로 조건에 맞는지 체크
			if(Check(idx))Make(idx + 1);

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			cin >> S[i][j];
		}
	}
	Make(0);

	return 0;
}