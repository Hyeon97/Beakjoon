#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
stack<int>S;
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		int num;
		cin >> s;
		if (s.compare("push") == 0) { cin >> num; S.push(num); }
		else if (!s.compare("pop")) {
			if (S.size()) { cout << S.top() << "\n"; S.pop(); }
			else cout << -1 << "\n";
		}
		else if (!s.compare("top")) {
			if (S.size())cout << S.top() << "\n";
			else cout << -1 << "\n";
		}
		else if (!s.compare("size")) { cout << S.size() << "\n"; }
		else if (!s.compare("empty")) {
			if (S.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	return 0;

	return 0;
}
