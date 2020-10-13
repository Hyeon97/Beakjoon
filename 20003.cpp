#include <iostream>
#include <limits.h>

using namespace std;

int N;
long long u[51], d[51];
long long U, D;

long long gcd(long long a, long long b) {//�ִ�����
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long lcm(long long a, long long b) {//�ּҰ����
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> u[i] >> d[i];
	}

	//1.�ּҰ���� ���ϱ�
	D = d[0];
	for (int i = 1; i < N; i++) {
		//U = gcd(U, u[i]);
		D = lcm(D, d[i]);
	}
	//2.���ڵ� �и� ���� �� ����
	for (int i = 0; i < N; i++) {
		u[i] *= (D/d[i]);
	}
	//3.�ٲ���ڵ��� �ִ����� ���ϱ�
	U = u[0];
	for (int i = 1; i < N; i++) {
		U = gcd(U, u[i]);
		//D = lcm(D, d[i]);
	}

	//���м��� �ƴѰ�� ���м��� �����
	long long T = gcd(U, D);
	U /= T;
	D /= T;
	//���
	cout << U << ' ' << D;

	return 0;
}