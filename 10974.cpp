#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int>v;
bool use[9];
void DFS() {
	if (v.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (use[i])continue;
		use[i] = true;
		v.push_back(i);
		DFS();
		use[i] = false;
		v.pop_back();
	}

}

int main() {

	cin >> n;

	DFS();

	return 0;
}