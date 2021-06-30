#include <iostream> 
#include <string>
#include <vector>

using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll solution(int w, int h) {
	ll g = (w < h) ? gcd(h, w) : gcd(w, h);
	ll answer = (ll)w * (ll)h;
	w /= g;
	h /= g;
	ll sub = (w == h) ? (ll)w : (ll)(w + h - 1);
	answer -= (sub * g);
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<solution(8,12);
	return 0;
}