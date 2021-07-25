#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ans = 987654321;
int map[51][51];
bool v[14];
vector<pair<int, int>>H, C;

void DFS(int idx, int cnt) {
	if (cnt == M) {
		int temp = 0;
		for (int i = 0; i < H.size(); i++) {
			int dist = 987654321;
			for (int j = 0; j < C.size(); j++) {
				if (v[j]) {
					dist = min(dist, abs(H[i].first - C[j].first) + abs(H[i].second - C[j].second));
				}
			}
			temp += dist;
		}
		if (temp < ans)ans = temp;
	}
	if (idx == C.size())return;
	v[idx] = true;
	DFS(idx + 1, cnt + 1);
	v[idx] = false;
	DFS(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1)H.push_back({ y,x });
			else if (map[y][x] == 2)C.push_back({ y,x });
		}
	}

	DFS(0, 0);
	cout << ans;
	return 0;
}
