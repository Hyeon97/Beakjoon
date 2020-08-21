#include <iostream>

using namespace std;
int N;
int arr[1000001];
int tempArr[1000001];
void merge(int low, int mid, int high)

{
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
			tempArr[k] = arr[i++];
		else
			tempArr[k] = arr[j++];
		k++;
	}
	if (i > mid)
		for (int idx = j; idx <= high; idx++)
			tempArr[k++] = arr[idx];
	else
		for (int idx = i; idx <= mid; idx++)
			tempArr[k++] = arr[idx];
	for (int idx = low; idx <= high; idx++)
		arr[idx] = tempArr[idx];
}


void mergeSort(int low, int high)
{
	if (high > low)
	{
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++)
		//cout << arr[i] << endl;
		printf("%d\n", arr[i]);
	return 0;
}
