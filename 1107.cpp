#include <iostream>
#include <cmath>
using namespace std;

int N,M;
int btn[10];//부서진 버튼

int check(int num) {
	//들어온 번호가 0인경우
	if (num == 0) {
		if (btn[num])return 0;
		else return 1;
	}
	int L = 0;
	//들어온번호가 0이 아닌경우
	while (num > 0) {
		//번호를 구성하는 버튼중 부서진 버튼이 있는경우
		if (btn[num % 10])return 0;
		num /= 10;
		L += 1;
	}
	return L;
}

int main() {
	cin >> N >> M;
	//망가진 버튼이 있는경우 버튼 입력받음
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		btn[temp]=1;
	}
	//100번에서부터 순수하게 +버튼만 눌러서 해당버튼에 도달한다고 가정(최대 누름)
	int result = abs(N - 100);
	if (result) {
		//0~50만이지만 반대로 내려오는 경우도 생각해줘야 함으로 2배
		for (int i = 0; i <= 1000000; i++) {
			int L = check(i);
			if (L > 0) {
				int cnt = abs(i - N);
				if (result > cnt + L)result = cnt + L;
			}
		}
	}
	cout << result;


	return 0;
}