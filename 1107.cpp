#include <iostream>
#include <cmath>
using namespace std;

int N,M;
int btn[10];//�μ��� ��ư

int check(int num) {
	//���� ��ȣ�� 0�ΰ��
	if (num == 0) {
		if (btn[num])return 0;
		else return 1;
	}
	int L = 0;
	//���¹�ȣ�� 0�� �ƴѰ��
	while (num > 0) {
		//��ȣ�� �����ϴ� ��ư�� �μ��� ��ư�� �ִ°��
		if (btn[num % 10])return 0;
		num /= 10;
		L += 1;
	}
	return L;
}

int main() {
	cin >> N >> M;
	//������ ��ư�� �ִ°�� ��ư �Է¹���
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		btn[temp]=1;
	}
	//100���������� �����ϰ� +��ư�� ������ �ش��ư�� �����Ѵٰ� ����(�ִ� ����)
	int result = abs(N - 100);
	if (result) {
		//0~50�������� �ݴ�� �������� ��쵵 ��������� ������ 2��
		for (int i = 0; i <= 1000000; i++) {
			int L = check(i);
			if (L > 0) {
				int cnt = abs(i - N);
				if (result > cnt + L)result = cnt + L;
			}
		}
	}
	cout << result;


	return 0;
}