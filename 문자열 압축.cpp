//���ڿ� ����
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	//�κй��ڿ��� �ִ� ���̴� ���� ���ڿ��� ����
	for (int l = 1; l <= s.length() / 2; l++) {	
		string temp;//���� ���ڿ�
		string sub = s.substr(0, l);//������ ���̸�ŭ �ڸ� ���ڿ�
		int cnt = 1;//�κ� ���ڿ� �ݺ� Ƚ��
		int i = 0;
		bool flag = true;
		for (i = l; i <= s.length(); i+=l) {
			if (sub == s.substr(i, l))cnt++;//���ڿ��� �Ȱ��� ���
			else {//���ڿ� �ٸ����
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
				//���ŵ��߿� ���̰� answer�� �ʰ��ϴ°�� �����ʿ� ����
				if (temp.length() > answer) { flag = false; break; }
				cnt = 1;
				sub = s.substr(i,l);//���ο� �κ� ���ڿ� ����
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