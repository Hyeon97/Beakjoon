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
	sort(V.begin(), V.end(), cmp1);//���۽ð� �������� ������
	sort(V.begin(), V.end(), cmp2);//������ �ð� �������� �ٽ����� 

	int count = 1;
	ll END = V.front().second;
	for (int i = 1; i < V.size(); i++) {//������ �ð��� �������� ���������¾��̵��� ����ֱ�
		if (V[i].first >= END) {
			END = V[i].second;
			count++;
		}
	}
	cout << count;


	return 0;
}
