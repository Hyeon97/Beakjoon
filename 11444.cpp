#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;
const ll M = 1000000007;

ll N;

vector<ll>dp1, dp2;

vector<ll> F(ll f) {
	if (f == 1) {//���� ���ڰ� 1�ΰ��
		return dp1;
	}
	else if (f == 2) {//���� ���ڰ� 2�ΰ��
		return dp2;
	}
	else if (f % 2) {//���� ���ڰ� Ȧ���� ���
		vector<ll>T1 = F((f - 1) / 2);
		vector<ll>T2 = T1;
		vector<ll>OUT;
		//T1 * T2
		ll temp1 = (T1[0] % M * T2[0] % M + T1[1] % M * T2[2] % M) % M;
		ll temp2 = (T1[2] % M * T2[0] % M + T1[3] % M * T2[2] % M) % M;
		ll temp3 = (T1[0] % M * T2[1] % M + T1[1] % M * T2[3] % M) % M;
		ll temp4 = (T1[2] % M * T2[1] % M + T1[3] % M * T2[3] % M) % M;
		//T1 * T2 �Ѱſ� dp1 ������ �� Ǫ��
		OUT.push_back((temp1 + temp2) % M);
		OUT.push_back((temp3 + temp4) % M);
		OUT.push_back((temp1) % M);
		OUT.push_back((temp3) % M);
		return OUT;
	}
	else {//¦���� ���
		vector<ll>T1 = F(f / 2);
		vector<ll>T2 = T1;
		vector<ll>OUT;
		//T1 * T2
		OUT.push_back((T1[0] % M * T2[0] % M + T1[1] % M * T2[2] % M) % M);
		OUT.push_back((T1[2] % M * T2[0] % M + T1[3] % M * T2[2] % M) % M);
		OUT.push_back((T1[0] % M * T2[1] % M + T1[1] % M * T2[3] % M) % M);
		OUT.push_back((T1[2] % M * T2[1] % M + T1[3] % M * T2[3] % M) % M);
		return OUT;
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	dp1.resize(4);
	dp2.resize(4);
	dp1[0] = dp1[1] = dp1[2] = 1;
	dp1[3] = 0;
	dp2[0] = 2;
	dp2[1] = dp2[2] = dp2[3] = 1;
	vector<ll>V1 = F(N);
	cout << (V1[1]) % M << '\n';
	return 0;
}