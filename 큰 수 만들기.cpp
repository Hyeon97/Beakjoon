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
			//answer�� ���� ������ ���� ���� ������ �������
			if (answer[answer.length() - 1] < number[i]) {
				//�������ڿ��� ���� + ���� ������� ���ڿ��� ���� �ٽᵵ E���� �۾����� ������
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