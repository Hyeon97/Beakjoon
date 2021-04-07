//��Ʈ��ũ �÷ο�(�ִ�����)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, ST, ED, val;
char st, ed;
int F[52][52];//���� �帣�� �ִ� �뷮
int C[52][52];//������ �� �뷮

vector<int>adj[52];//�� ������ ���� ����

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> st >> ed >> val;
		if ('A' <= st && st <= 'Z') ST = st - 'A';
		else ST = st - 'a' + 26;

		if ('A' <= ed && ed <= 'Z')ED = ed - 'A';
		else ED = ed - 'a' + 26;

		C[ST][ED] += val;
		C[ED][ST] += val;
		//�����߰�
		adj[ST].push_back(ED);
		adj[ED].push_back(ST);
	}
	
	int TotalFlow = 0, S = 0, T = 'Z' - 'A';//S == source, T == sink
	
	while (1) {
		int prev[52];//Ž�� ��� �����
		for (int i = 0; i < 52; i++)prev[i] = -1;
		queue<int>q;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {

				int next = adj[cur][i];

				if (prev[next] != -1)continue;//�湮�Ѱ� ����ħ

				if (C[cur][next] - F[cur][next] > 0) {//�ش� ������ �� �˷� - ���� �ش簣���� �帣�� �뷮 >0 >> ���� �� �带�� ����
					q.push(next);
					prev[next] = cur;
					if (next == T)break;//���� ��ġ���� ���� ��尡 ���������� ��� ����
				}
			}
		}
		if (prev[T] == -1)break;//���������� ��ΰ� ���°�� >> ���� ������ �ʿ� ����

		int flow = 987654321;
		//��θ� Ÿ���鼭 ���� ���� ������ ������
		for (int i = T; i != S; i = prev[i]) {
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}

		for (int i = T; i != S; i = prev[i]) {
			F[prev[i]][i] += flow;//���������� �ּ� ������ŭ +
			F[i][prev[i]] -= flow;//���������� �� �带�� �ִ� ���� - ���� �帣�� ����
		}
		TotalFlow += flow;

	}
	cout << TotalFlow << '\n';
	return 0;
}