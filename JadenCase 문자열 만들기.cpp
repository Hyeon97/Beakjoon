#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {//문장 맨 첫 글자
			if ('a' <= s[i] && s[i] <= 'z') {
				answer += (s[i] - 32);
			}
			else answer += s[i];
		}
		else {
			if (s[i - 1] == ' ' && 'a' <= s[i] && s[i] <= 'z') answer += (s[i] - 32);
			else if (s[i - 1] != ' ' && 'A' <= s[i] && s[i] <= 'Z') {
				answer += (s[i] + 32);
			}
			else answer += s[i];
		}
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("a 3Sdf ffTt Afftt fftt3133Sdf");
	return 0;
}