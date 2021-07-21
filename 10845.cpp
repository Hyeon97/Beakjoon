#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<int>Q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		int num;
		cin >> s;
		if (s.compare("push") == 0) { cin >> num; Q.push(num); }
		else if (!s.compare("pop")) {
			if (Q.size()) { cout << Q.front() << "\n"; Q.pop(); }
			else cout << -1 << "\n";
		}
		else if (!s.compare("front")) {
			if (Q.size())cout << Q.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (!s.compare("back")) {
			if (Q.size())cout << Q.back() << "\n";
			else cout << -1 << "\n";
		}
		else if (!s.compare("size")) { cout << Q.size() << "\n"; }
		else if (!s.compare("empty")) {
			if (Q.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	return 0;
}
