#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

string N;
int K;
bool vi[1000001];
queue<pair<int, int>>q;
vector<int>v;

int ch(string s) {
	int sum = 0;
	for (int i = s.length() - 1, up = 1; i >= 0; i--, up *= 10) sum += (s[i] - '0') * up;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	q.push({ ch(N),0 });
	int temp = 1;
	while (!q.empty()) {
		int S = q.front().first;
		int n = q.front().second;
		q.pop();
		if (n == K) {
			v.push_back(S);
			continue;
		}
		if (n != temp) {
			for (int i = 1; i < 1000001; i++)vi[i] = 0;
			temp = n;
		}
		string s;
		while (S) {
			s += S % 10+'0';
			S /= 10;
		}
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.length() - 1; i++) {
			for (int j = i + 1; j < s.length(); j++) {
				if (i == 0 && s[j] == '0')continue;
				string st = s;
				char t = st[i];
				st[i] = st[j];
				st[j] = t;
				if (!vi[ch(st)]) {
					vi[ch(st)] = true;
					q.push({ ch(st),n + 1 });
				}
			}
		}
	}
	if (v.size() == 0)cout << -1;
	else {
		sort(v.begin(), v.end(), greater<int>());
		cout << v[0];
	}
	return 0;
}
