#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string>temp;
	for (int i = 0; i < numbers.size(); i++) {
		string st;
		if (!numbers[i])st = '0';
		else {
			while (numbers[i]) {
				st += (numbers[i] % 10) + '0';
				numbers[i] /= 10;
			}
		}
		reverse(st.begin(), st.end());
		temp.push_back(st);
	}
	sort(temp.begin(), temp.end(), cmp);
	for (int i = 0; i < temp.size(); i++)answer += temp[i];
	if (answer[0] == '0')answer = '0';
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution({ 0,0});
	return 0;
}