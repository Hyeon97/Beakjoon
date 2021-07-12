#include <iostream> 
#include <string>
#include <algorithm>

using namespace std;



string solution(string number, int k) {
	string answer = "";
	int E = number.length() - k;
	for (int i = 0; i < number.length(); i++) {
		if (!answer.length())answer += number[i];
		else {
			//answer의 제일 마지막 값이 현재 값보다 작은경우
			if (answer[answer.length() - 1] < number[i]) {
				//남은문자열의 길이 + 지금 만들어진 문자열의 길이 다써도 E보다 작아지기 전까지
				while (1) {
					if (!answer.length())break;
					if (answer.length() + number.length() - i <= E)break;
					if (answer[answer.length() - 1] >= number[i])break;

					answer.pop_back();
				}
			}
			if (answer.length() >= E)continue;
			answer += number[i];
		}
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("1000",1);
	return 0;
}