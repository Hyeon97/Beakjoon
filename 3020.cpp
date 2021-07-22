#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define ll long long
using namespace std;

int N, H;
vector<int>J, S;//종유석, 석순


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> H;
	for (int i = 0, temp; i < N; i++) {
		cin >> temp;
		if (i % 2)S.push_back(temp);//석순
		else J.push_back(temp);//종유석
	}
	sort(J.begin(), J.end());
	sort(S.begin(), S.end());
	reverse(J.begin(), J.end());
	int Jidx = 0, Sidx = 0,ans=987654321,cnt=0;
	for (int i = 1; i <= H; i++) {
		int temp = 0;
		//가장 처음 부딫히는 석순
		while (Sidx < S.size()) {
			if(i<=S[Sidx]){
				temp += (S.size() - Sidx);
				break;
			}
			Sidx++;
		}
		//맨처음으로 안부딫히는 종유석
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
