#include <iostream>
#include <algorithm>


using namespace std;
int arr[10001];
int n;
long long int sum;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sort(arr, arr + n);
	//(-,-) (-,0)�� ��Ʈ�� �����ְ� 1������ ���� ū������ ������
	int i = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] > 0)break;
		if (arr[i] <= 0 && ( arr[i + 1] <= 0 && i+1 < n )) {
			sum += arr[i] * arr[i + 1];
			i++;
		}
		else sum += arr[i];
	}
	for (int j = n - 1; j >= i; j--) {//����� ����� ����
		//�μ� ��� 1�� �ƴѰ�쿣 ������
		//���� �ϳ��� 1�ΰ�쿣 ���� ���� ������
		//1�� ����� ������ ������� ����
		if ( ( arr[j] != 1 && arr[j]>0 ) && ( arr[j - 1] != 1 && arr[j-1] >0 )) {
			sum += arr[j] * arr[j - 1];
			j--;
		}
		else {
			sum += arr[j];
		}
	}
	cout << sum;


	return 0;
}
