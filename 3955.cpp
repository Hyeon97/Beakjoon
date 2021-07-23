#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long
#define OUT 1000000000
using namespace std;

//x 인당 나눠줄 사탕수
//y 사탕봉지수
//A * x + 1 = B * y
//Ax+By = C의 형태로 변환
//A(-x) + By = 1
int test;
ll K, C;
ll s0 = 1, t0 = 0, r0;
ll s1 = 0, t1 = 1, r1;
ll temp;

ll gcd(ll a, ll b) {
	while (b) {
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
//확장유클리드
void EGR(ll a, ll b) {
	s0 = t1 = 1;
	s1 = t0 = 0;
	r0 = a; r1 = b;
	while (r1) {
		ll q = r0 / r1;
		temp = r0 - q * r1;
		r0 = r1;
		r1 = temp;

		temp = s0 - q * s1;
		s0 = s1;
		s1 = temp;

		temp = t0 - q * t1;
		t0 = t1;
		t1 = temp;
	}
	//return s0,t0,r0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> test;
	while (test--) {
		cin >> K >> C;
		if (C == 1) {//봉지당 사탕이 1개인경우
			if (K + 1 > OUT)cout << "IMPOSSIBLE\n";
			else cout << K + 1 << '\n';
		}
		else if (K == 1) {
			cout << 1 << '\n';
		}
		else if (gcd(K,C) != 1)cout << "IMPOSSIBLE\n";
		else {
			EGR(K, C);
			while (t0 < 0)t0 += t1;
			cout << t0 << '\n';
		}
	}

	return 0;
}
