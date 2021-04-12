//구현
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<string>V;
bool cmp(string a, string b) {
	//대상 숫자 2개를 더한게 더 큰걸 리턴해줌
	return a + b > b + a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	string temp, max_s = "";
	//입력을 받으면서 가장 큰 숫자하나는 따로 저장해줌
	for (int i = 0; i < K; i++) {
		cin >> temp;
		V.push_back(temp);
		if ((max_s.length() == temp.length() && max_s < temp) || (max_s.length() < temp.length()))max_s = temp;
	}
	//추가로 더 넣을수 있는 만큼 제일 큰 숫자를 넣어줌
	for (int i = 0; i < N-K; i++)V.push_back(max_s);
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < V.size(); i++)cout << V[i];
	return 0;
}