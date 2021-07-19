#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
bool use[27];
int n, k, ans;
string s;
vector<string>S;

void DFS(int idx, int left) {
	if (left==0) {
		bool ch = true;
		int cnt = 0;
		for (int i = 0; i < S.size(); i++) {
			ch = true;
			for (int j = 0; j < S[i].length(); j++) {
				if (!use[S[i][j] - 'a']) {
					ch = false; break;
				}
			}
			if (ch)cnt++;
		}
		if (cnt > ans)ans = cnt;
		return;
	}
	else {
		for (int i = idx; i < 27; i++) {
			if (!use[i]) {
				use[i] = 1;
				DFS(i+ 1, left - 1);
				use[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	//문자열 가공
	for (int i = 0; i < n; i++) {
		cin >> s;
		s = s.substr(4);
		for (int j = 0; j < 4; j++)s.pop_back();
		S.push_back(s);
	}
	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}
	use['a' - 'a'] = use['c' - 'a'] = use['i' - 'a'] = use['t' - 'a'] = use['n' - 'a'] = 1;
	DFS(0, k - 5);
	cout << ans << '\n';

	return 0;
}
