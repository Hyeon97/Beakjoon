#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, L, P, D;
priority_queue< int >pq;
pair <int, int> arr[10001];//�Ÿ�, ���ᷮ
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	cin >> L >> P;
	sort(arr, arr + N);
	int idx = 0;
	while (P < L) {
		while (arr[idx].first<=P) {//���� ������ �ִ� ����� �����ִ� ��� ������ ����
			if (idx == N)break;
			pq.push(arr[idx++].second);//�ش��������� �⸧ �� ����
		}
		if (!pq.size())break;//�ֿ�ҿ� �������ϴ� ���
		D++;//������ �湮Ƚ�� ++
		P += pq.top();//���� �߰�
		pq.pop();
	}
	P < L ? cout << -1 : cout << D;

	return 0;
}
