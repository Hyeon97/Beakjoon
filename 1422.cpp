//����
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<string>V;
bool cmp(string a, string b) {
	//��� ���� 2���� ���Ѱ� �� ū�� ��������
	return a + b > b + a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	string temp, max_s = "";
	//�Է��� �����鼭 ���� ū �����ϳ��� ���� ��������
	for (int i = 0; i < K; i++) {
		cin >> temp;
		V.push_back(temp);
		if ((max_s.length() == temp.length() && max_s < temp) || (max_s.length() < temp.length()))max_s = temp;
	}
	//�߰��� �� ������ �ִ� ��ŭ ���� ū ���ڸ� �־���
	for (int i = 0; i < N-K; i++)V.push_back(max_s);
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < V.size(); i++)cout << V[i];
	return 0;
}