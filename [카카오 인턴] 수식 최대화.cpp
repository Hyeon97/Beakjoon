#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
	long long answer = 0;
	vector<long long>num;
	vector<char>op;
	string Op = "*+-";
	//숫자 연산자 분리
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') op.push_back(expression[i]);
		else {
			string temp;
			for (int j = i; j <= expression.length(); j++) {
				if (j == expression.length() || expression[j] == '+' || expression[j] == '-' || expression[j] == '*') {
					long long sum = 0;
					for (int k = temp.length() - 1, u = 1; k >= 0; k--, u *= 10) {
						sum += (temp[k] - '0') * u;
					}
					num.push_back(sum);
					i = j - 1; break;
				}
				temp += expression[j];
			}
		}
	}
	//연산자 우선순위 지정후 연산
	do {
		//숫자, 연산자 복사
		vector<long long>tn = num;
		vector<char>top = op;
		for (int i = 0, idx = 0; i < 3; i++, idx++) {//연산자 우선순위대로 계산
			for (int j = 0; j < top.size(); j++) {
				if (top[j] == Op[idx]) {
					long long t = 0;
					if (top[j] == '+') { t = tn[j] + tn[j + 1]; }
					else if (top[j] == '-') { t = tn[j] - tn[j + 1]; }
					else if (top[j] == '*') { t = tn[j] * tn[j + 1]; }
					top.erase(top.begin() + j);
					tn[j + 1] = t;
					tn.erase(tn.begin() + j);
					j--;
				}
			}
		}
		if (abs(tn[0]) > answer)answer = abs(tn[0]);
	} while (next_permutation(Op.begin(), Op.end()));
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<solution("200-300-500-600*40+500+500");
	return 0;
}