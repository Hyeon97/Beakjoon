#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(string s) {
	int cnt = 0, time = 0;
	while (s.compare("1")) {
		time++;
		int num = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1')num++;
			else cnt++;
		}
		string temp;
		while (num) {
			temp += (num % 2 + '0');
			num /= 2;
		}
		reverse(temp.begin(), temp.end());
		s = temp;
	}
	return {time, cnt};
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("110010101001");
	return 0;
}