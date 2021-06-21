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
	//(-,-) (-,0)을 세트로 묶어주고 1제외한 값을 큰수부터 묶어줌
	int i = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] > 0)break;
		if (arr[i] <= 0 && ( arr[i + 1] <= 0 && i+1 < n )) {
			sum += arr[i] * arr[i + 1];
			i++;
		}
		else sum += arr[i];
	}
	for (int j = n - 1; j >= i; j--) {//여기는 양수만 남음
		//두수 모두 1이 아닌경우엔 곱해줌
		//둘중 하나라도 1인경우엔 각각 따로 더해줌
		//1은 절대로 곱셈에 사용하지 않음
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
