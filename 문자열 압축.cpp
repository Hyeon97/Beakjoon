//문자열 압축
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	//부분문자열의 최대 길이는 들어온 문자열의 절반
	for (int l = 1; l <= s.length() / 2; l++) {	
		string temp;//최종 문자열
		string sub = s.substr(0, l);//정해진 길이만큼 자른 문자열
		int cnt = 1;//부분 문자열 반복 횟수
		int i = 0;
		bool flag = true;
		for (i = l; i <= s.length(); i+=l) {
			if (sub == s.substr(i, l))cnt++;//문자열이 똑같은 경우
			else {//문자열 다른경우
				if (cnt == 1) {
					temp += sub;
				}
				else {
					string num;
					while (cnt) {
						num += (cnt % 10 + '0');
						cnt /= 10;
					}
					for (int idx = num.length() - 1; idx >= 0; idx--)temp += num[idx];
					temp += sub;
				}
				//갱신도중에 길이가 answer을 초과하는경우 더볼필요 없음
				if (temp.length() > answer) { flag = false; break; }
				cnt = 1;
				sub = s.substr(i,l);//새로운 부분 문자열 추출
			}
		}
		if (i > s.length() && flag) {
			temp += s.substr(i-l);
		}
		answer = answer > temp.length() ? temp.length() : answer;
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution("a");
	return 0;
}