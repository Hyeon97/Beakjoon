//124 나라의 숫자
#include <iostream> 
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	int div=n,mod;
	while (div) {
		mod = div % 3;
		div /= 3;
		if (mod == 1) {
			answer = '1' + answer;
		}
		else if (mod == 2) {
			answer = '2' + answer;
		}
		else {
			answer = '4' + answer;
			div--;
		}
	}
	
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution(4);
	return 0;
}