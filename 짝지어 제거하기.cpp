//짝지어 제거하기
#include <iostream> 
#include <vector>


using namespace std;

//string 2개 사용 버전
//int solution(string s2)
//{
//    int answer = -1;
//    string s1;
//    int idx = s2.length() - 1;
//    while (1) {
//        if (idx - 1 >= 0 && s2[idx] == s2[idx - 1]) {
//            idx -= 2;
//            s2.pop_back();
//            s2.pop_back();
//        }
//        else if (s1.length()>=1 && s2[idx] == s1[s1.length() - 1]) {
//            idx -= 1;
//            s2.pop_back();
//            s1.pop_back();
//        }
//        else {
//            s1.push_back(s2[idx]);
//            idx--;
//            s2.pop_back();
//        }
//        if (idx < 0)break;
//    }
//    answer = s1.length() >= 1 ? 0 : 1;
//    return answer;
//}

//stack 사용 버전
#include <stack>
int solution(string s)
{
	int answer = 0;
	stack<char>st;
	for (int i = 0; i < s.length(); i++) {
		if (st.empty() || st.top() != s[i])st.push(s[i]);
		else st.pop();
	}
	if (st.empty())answer = 1;
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << solution("bccbcc");
	return 0;
}