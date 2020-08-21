#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char S[16];
char out[16];
void BACK(int idx, int count) {
	if (count == l) {
		int ja = 0, mo = 0;
		for (int i = 0; i < l; i++) {
			if (out[i] == 'a' || out[i] == 'e' || out[i] == 'i' || out[i] == 'o' || out[i] == 'u')mo++;
			else ja++;
		}
		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < l; i++) {
				cout << out[i];
			}
			cout << "\n";
		}
		return;
	}
	for (int i = idx; i < c; i++) {
		out[count] = S[i];
		BACK(i + 1, count + 1);
	}
}


int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> S[i];
	}
	sort(S, S + c);
	BACK(0, 0);

	return 0;
}
