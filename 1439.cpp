#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int z = 0, o = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s; 
	
	s[0] == '0' ?  z++ : o++;
	for (int i = 1;i < s.length();i++) { 
		if (s[i] != s[i - 1]) { //이전의 문자와 다를경우 
			if (s[i] == '1') o++; 
			else if (s[i] == '0') z++; } 
	} 

	cout << (o < z ? o : z);


	return 0;
}
