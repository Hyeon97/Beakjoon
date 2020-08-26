#include <iostream>

using namespace std;

char Boo[10];
int k, NUM[10];

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> Boo[i];
	}

	int n = 9, l = 0;
	for (int i = 0; i <= k; i++) {
		if (i == k || Boo[i] == '>') {
			for (int j = i; j >= l; j--) {
				NUM[j] = n--;
			}
			l = i + 1;
		}
	}
	for (int i = 0; i <= k; i++) {
		cout << NUM[i];
	}
	cout << '\n';
	 n = 0, l = 0;

	for (int i = 0; i <= k; i++) {
		if (i == k || Boo[i] == '<') {
			for (int j = i; j >= l; j--)
				NUM[j] = n++;

			l = i + 1;
		}
	}

	for (int i = 0; i <= k; i++) {
		cout << NUM[i];
	}

	return 0;
}
// 4ms
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int k;
//char Boo[9];
//int arr[10];
//vector <int> V;
//vector<string>S;
//void Find(int idx, int cnt) {
//	if (cnt == k + 1) {
//		string temp;
//		for (int i = 0; i < cnt; i++) {
//			temp += V[i]+'0';		
//		}
//		S.push_back(temp);
//		return;
//	}
//	for (int i = 9; i >= 0; i--) {
//		if (!arr[i]) {
//			if (V.size() == 0) {
//				V.push_back(i);
//				arr[i] = true;
//				Find(idx, cnt + 1);
//				arr[i] = false;
//				V.pop_back();
//			}
//			else if (V[idx] < i && Boo[idx] == '<' || V[idx] > i&& Boo[idx] == '>') {
//				V.push_back(i);
//				arr[i] = true;
//				Find(idx + 1, cnt + 1);
//				arr[i] = false;
//				V.pop_back();
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> k;
//	for (int i = 0; i < k; i++) {
//		cin >> Boo[i];
//	}
//	Find(0, 0);
//	cout << S[0] << '\n' << S[S.size() - 1];
//
//	return 0;
//}