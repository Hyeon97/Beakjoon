#include <iostream>
#include <string>
using namespace std;

string S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> S;
	int result = 0;
	for (int i = 0; i <= S.length(); i++) {
		if ('0' <= S[i] && S[i] <= '9') {
			string temp;
			for (int j = i; ; j++) {
				if (S[j] == '+' || S[j] == '-' || S[j] == '\0') {
					i = (j - 1);
					int tempsum = 0;
					for (int k = temp.length() - 1, p = 1; k >= 0; k--, p *= 10) {
						tempsum += (temp[k]-'0') * p;
					}
					result += tempsum;
					break;
				}
				temp += S[j];
			}
		}
		else if (S[i] == '+') {
			string temp;
			for (int j = i+1; ; j++) {
				if (S[j] == '+' || S[j] == '-' || S[j] == '\0') {
					i = (j - 1);
					int tempsum = 0;
					for (int k = temp.length() - 1, p = 1; k >= 0; k--, p *= 10) {
						tempsum += (temp[k] - '0') * p;
					}
					result += tempsum;
					break;
				}
				temp += S[j];
			}
		}
		else if (S[i] == '-') {
			string temp;
			int tempsum = 0;
			for (int j = i+1; ; j++) {
				if (S[j] == '-' || S[j] == '\0') {
					i = (j - 1);
					for (int k = temp.length() - 1, p = 1; k >= 0; k--, p *= 10) {
						tempsum += (temp[k] - '0') * p;
					}
					result -= tempsum;
					break;
				}
				else if (S[j] == '+') {
					for (int k = temp.length() - 1, p = 1; k >= 0; k--, p *= 10) {
						tempsum += (temp[k] - '0') * p;
					}
					temp = "";
				}
				else temp += S[j];
			}
		}

	}
	cout << result;


	return 0;
}

