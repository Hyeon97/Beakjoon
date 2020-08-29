#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

int N;
vector<pair<ll, ll>>V;

bool cmp1(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		V.push_back({ a,b });
	}
	sort(V.begin(), V.end(), cmp1);//시작시간 기준으로 정렬후
	sort(V.begin(), V.end(), cmp2);//끝나는 시간 기준으로 다시정렬 

	int count = 1;
	ll END = V.front().second;
	for (int i = 1; i < V.size(); i++) {//끝나는 시간을 기준으로 빨리끝나는아이들을 집어넣기
		if (V[i].first >= END) {
			END = V[i].second;
			count++;
		}
	}
	cout << count;


	return 0;
}
