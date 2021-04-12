//구현
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, N, M, a, b;
vector< pair < int, int> >St;
int book[1001];

//학생들이 원하는 책의 목록을 뒤에서 부터 앞으로 정렬해줌
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second < b.second)return true;
	else {
		if (a.second == b.second) {
			if (a.first < b.first)return true;
		}
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < 1001; i++)book[i] = 0;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			St.push_back({ a,b });
		}
		sort(St.begin(), St.end(), cmp);
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = St[i].first; j <= St[i].second; j++) {
				if (!book[j]) {
					cnt++;
					book[j] = 1;
					break;
				}
			}
		}
		cout << cnt << '\n';
		St.clear();
	}
	return 0;
}