#include <iostream>
#include <limits.h>

using namespace std;

int N;
long long u[51], d[51];
long long U, D;

long long gcd(long long a, long long b) {//최대공약수
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long lcm(long long a, long long b) {//최소공배수
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> u[i] >> d[i];
	}

	//1.최소공배수 구하기
	D = d[0];
	for (int i = 1; i < N; i++) {
		//U = gcd(U, u[i]);
		D = lcm(D, d[i]);
	}
	//2.분자들 분모에 맟춰 값 수정
	for (int i = 0; i < N; i++) {
		u[i] *= (D/d[i]);
	}
	//3.바뀐분자들의 최대공약수 구하기
	U = u[0];
	for (int i = 1; i < N; i++) {
		U = gcd(U, u[i]);
		//D = lcm(D, d[i]);
	}

	//기약분수가 아닌경우 기약분수로 만들기
	long long T = gcd(U, D);
	U /= T;
	D /= T;
	//출력
	cout << U << ' ' << D;

	return 0;
}