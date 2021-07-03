#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string p) {
	string answer = "";
	string u, v;
	int l = 0, r = 0;
	int i;
	//u,v �и�
	//u�и�
	for (i = 0; i < p.length(); i++) {
		if (l != 0 && r != 0 && l == r)break;
		if (p[i] == '(')l++;
		if (p[i] == ')')r++;
		u += p[i];
	}
	//v�и�
	for (i; i < p.length(); i++) {
		v += p[i];
	}
	//u �˻�
	string temp;
	bool flag = true;
	for (int j = 0; j < u.length(); j++) {
		if (u[j] == '(')temp.push_back(u[j]);
		else {
			if (temp.length() == 0) {
				flag = false;
				break;
			}
			else {
				if (temp[temp.length() - 1] == '(') {
					temp.pop_back();
				}
				else {
					flag = false;
					break;
				}
			}
		}
	}
	if (!flag) {//�����ΰ��
		temp.clear();
		temp += '(';
		if(v.length())v = solution(v);
		temp += v;
		v.clear();
		temp += ')';
		for (int i = 1; i < u.length() - 1; i++) {
			temp += u[i] == ')' ? '(' : ')';
		}
		u = temp;
	}
	else {//�ùٸ� ��ȣ
		if (v.length())v = solution(v);
	}
	answer += u;
	answer += v;

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("()))((()");
	return 0;
}