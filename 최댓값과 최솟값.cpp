#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>num;

int ch(string s, int st, int ty) {
	string temp;
	int sum = 0, i;
	for (i = st; i < s.length(); i++) {
		if (s[i] == '-' || s[i] == ' ')break;
		temp += s[i];
	}
	for (int j = temp.length() - 1, u = 1; j >= 0; j--, u *= 10)sum += (temp[j] - '0') * u;
	//À½¼ö
	if (ty == 0) sum *= -1;
	num.push_back(sum);
	return i;
}

string ch2(int n) {
	string temp;
	bool flag = false;
	if (n < 0)flag = true, n*=-1;
	while (n) {
		temp += (n % 10 + '0');
		n /= 10;
	}
	if (flag)temp += '-';
	reverse(temp.begin(), temp.end());
	return temp;
}

string solution(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			i=ch(s, i + 1, 0)-1;
		}
		else if ('0' <= s[i] && s[i] <= '9') {
			i=ch(s, i, 1)-1;
		}
	}
	sort(num.begin(), num.end());

	return ch2(num.front()) + ' '+ ch2(num.back());
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<solution("11 21 31 41");
	return 0;
}