//��ü �迭�Է¹���
//���� �̿� �ش籸������ ���� ���� ���ڸ��� ����鼭 Ž��

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define ll long long

using namespace std;


int N, L;
vector<long long>arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0, temp; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	deque<pair<ll, ll>>dq;//��������, ��
	for (int i = 0; i < N; i++) {
		//���� : i - 1 + L ~ i
		//���� �ۿ� �ִ� �Ʒ��� ���ڵ� ����
		if (!dq.empty() && dq.front().second <= i - L)dq.pop_front();
		//������ ���� ���� ���ڸ� ���ܵ�
		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();
		//���� �� �־���
		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
	}

	return 0;
}
