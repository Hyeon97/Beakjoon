#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long
using namespace std;

int N, H;
vector<int>J, S;//������, ����


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> H;
	for (int i = 0, temp; i < N; i++) {
		cin >> temp;
		if (i % 2)S.push_back(temp);//����
		else J.push_back(temp);//������
	}
	sort(J.begin(), J.end());
	sort(S.begin(), S.end());
	reverse(J.begin(), J.end());
	int Jidx = 0, Sidx = 0,ans=987654321,cnt=0;
	for (int i = 1; i <= H; i++) {
		int temp = 0;
		//���� ó�� �΋H���� ����
		while (Sidx < S.size()) {
			if(i<=S[Sidx]){
				temp += (S.size() - Sidx);
				break;
			}
			Sidx++;
		}
		//��ó������ �Ⱥ΋H���� ������
		while (Jidx < J.size()) {
			if (H - J[Jidx] >= i) break;
			Jidx++;
		}
		temp += Jidx;
		if (temp == ans)cnt++;
		else if (temp < ans) {
			ans = temp;
			cnt = 1;
		}
	}
	cout << ans << ' ' << cnt;
	return 0;
}
