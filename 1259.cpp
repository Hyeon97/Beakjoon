#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string num;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		//num.clear();
		cin >> num;
		if (num=="0")break;
		int s = num.size();
		bool NO = false;
		for (int i = 0; i < s/2; i++) {
			if (num[i] != num[s -1- i]) {
				NO = true;
				break;
			}
		}
		if (NO)cout << "no\n";
		else cout << "yes\n";

	}
	return 0;
}