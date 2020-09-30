//ũ�罺Į
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct T {
	int x;
	int y;
	int z;
	int num;
}T;

typedef struct Kru {
	int start;
	int end;
	int cost;
}Kru;

int N;
T arr[100001];
vector<Kru>G;
int P[100001];

bool operator<(const Kru& A, const Kru& B) {
	if (A.cost < B.cost)return true;
	return false;
}
bool cmpx(const T& a, const T& b) {
	if (a.x < b.x)return true;
	return false;
}
bool cmpy(const T& a, const T& b) {
	if (a.y < b.y)return true;
	return false;
}
bool cmpz(const T& a, const T& b) {
	if (a.z < b.z)return true;
	return false;
}
int getP(int x) {//�θ� ã��
	if (x == P[x])return x;
	return P[x] = getP(P[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	//�� ������ ��ǥ �Է¹���
	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
		//�ش� ������ ��ȣ
		arr[i].num = i + 1;
		//���ÿ� �θ�迭 �ʱ�ȭ
		P[i + 1] = i + 1;
	}
	//x,y,z�� ���ÿ��ϸ� �޸� �ʰ� �߻� ���� ���� ���� ���� �������ֱ�
	sort(arr, arr + N, cmpx);
	for (int i = 0; i < N - 1; i++) {
		int temp = arr[i].x - arr[i + 1].x;
		if (temp < 0)temp *= -1;
		G.push_back({ arr[i].num,arr[i + 1].num, temp });
	}
	sort(arr, arr + N, cmpy);
	for (int i = 0; i < N - 1; i++) {
		int temp = arr[i].y - arr[i + 1].y;
		if (temp < 0)temp *= -1;
		G.push_back({ arr[i].num,arr[i + 1].num, temp });
	}
	sort(arr, arr + N, cmpz);
	for (int i = 0; i < N - 1; i++) {
		int temp = arr[i].z - arr[i + 1].z;
		if (temp < 0)temp *= -1;
		G.push_back({ arr[i].num,arr[i + 1].num, temp });
	}
	//����ġ �������� ����
	sort(G.begin(), G.end());
	int ans = 0;
	for (int i = 0; i < G.size(); i++) {
		int st = G[i].start;
		int ed = G[i].end;
		int cost = G[i].cost;
		st = getP(st);
		ed = getP(ed);
		if (st == ed)continue;
		ans += cost;
		P[st] = ed;
	}
	cout << ans;
	return 0;
}