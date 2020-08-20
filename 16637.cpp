#include <iostream>
#include <algorithm>

using namespace std;

char S[20], op;
int n, result;

int cal(int val, int val2, char op) {
	if (op == '+')return val + val2;
	else if (op == '-')return val - val2;
	else if (op == '*')return val * val2;
}

void DFS(int sum, int idx) {
	if (idx >= n) {
		result = max(result, sum);
		return;
	}
	//연산방법 2가지
	//1.괄호를 씌우고 연산 >> 현재 숫자 , 다음 숫자, 다다음 숫자
	//2.괄호를 씌우지 않고 연산 >> 현재 숫자, 다음 숫자

	char op = (idx >= 1) ? S[idx - 1] : '+';
	int temp = cal(sum, S[idx] - '0', op);

	//괄호 없이 그냥 연산만 진행
	DFS(temp, idx + 2);

	if (idx < n - 2) {//괄호를 씌운경우
		temp = cal(S[idx] - '0', S[idx + 2] - '0', S[idx + 1]);
		temp = cal(sum, temp, op);
		DFS(temp, idx + 4);
	}


}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	result -= 2147483648;
	DFS(0, 0);
	cout << result;

	return 0;
}