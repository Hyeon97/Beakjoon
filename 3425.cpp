#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

#define ll long long
using namespace std;
vector<string>od;//명령어 저장 배열
vector<ll>NUM;//NUM일떄 받는 숫자 저장
stack<ll>S;
ll temp, temp2;
int POP() {
	if (S.empty())return 1;
	S.pop();
	return 0;
}

int INV() {
	if (S.empty())return 1;
	temp = -(S.top());
	S.pop();
	S.push(temp);
	return 0;
}

int DUP() {
	if (S.empty())return 1;
	S.push(S.top());
	return 0;
}

int SWP() {
	if (S.empty() || S.size() < 2)return 1;
	temp = S.top();
	S.pop();
	temp2 = S.top();
	S.pop();
	S.push(temp);
	S.push(temp2);
	return 0;
}

int ADD() {
	if (S.empty() || S.size() < 2)return 1;
	temp = S.top();
	S.pop();
	temp += S.top();
	S.pop();
	S.push(temp);
	return 0;
}

int SUB() {
	if (S.empty() || S.size() < 2)return 1;
	temp = S.top();
	S.pop();
	temp = S.top() - temp;
	S.pop();
	S.push(temp);
	return 0;
}

int MUL() {
	if (S.empty() || S.size() < 2)return 1;
	temp = S.top();
	S.pop();
	temp *= S.top();
	S.pop();
	S.push(temp);
	return 0;
}

int DIV() {
	int m = 0;
	if (S.empty() || S.size() < 2)return 1;
	temp = S.top();
	if (temp < 0)m++;
	if (temp == 0)return 1;
	S.pop();
	temp2 = S.top();
	if (temp2 < 0)m++;
	temp = temp2 / temp;
	if (m == 1)temp = -(abs(temp));
	else temp = abs(temp);
	S.pop();
	S.push(temp);
	return 0;
}

int MOD() {
	int m = 0;
	if (S.empty() || S.size() < 2)return 1;
	temp = S.top();
	if (temp == 0)return 1;
	S.pop();
	temp2 = S.top();
	if (temp2 < 0)m++;
	temp = temp2 % temp;
	if (m == 1)temp = -(abs(temp));
	else temp = abs(temp);
	S.pop();
	S.push(temp);
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	while (1) {
		while (1) {
			cin >> s;
			if (s == "NUM") {
				cin >> temp;
				NUM.push_back(temp);
			}
			if (s == "END")break;
			if (s == "QUIT")return 0;
			od.push_back(s);
		}
		int num;
		cin >> num;
		while (num--) {
			int n = 0, error = 0;
			cin >> temp;
			S.push(temp);
			for (int i = 0; i < od.size(); i++) {
				if (od[i] == "NUM") S.push(NUM[n++]);
				else if (od[i] == "POP") error = POP();
				else if (od[i] == "INV") error = INV();
				else if (od[i] == "DUP") error = DUP();
				else if (od[i] == "SWP") error = SWP();
				else if (od[i] == "ADD") error = ADD();
				else if (od[i] == "SUB") error = SUB();
				else if (od[i] == "MUL") error = MUL();
				else if (od[i] == "DIV") error = DIV();
				else if (od[i] == "MOD") error = MOD();
				if (!S.empty() && (S.top() > 1000000000 || S.top() < -1000000000))error = 1;
				if (error == 1)break;
			}
			if (error == 1 || S.size() != 1)cout << "ERROR\n";
			else cout << S.top() << "\n";
			while (!S.empty())S.pop();
		}
		od.clear();
		NUM.clear();
		cout << "\n";
	}

	return 0;
}
