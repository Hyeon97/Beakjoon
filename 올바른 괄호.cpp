#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//스택사용
//bool solution(string s)
//{
//    stack<char>st;
//    for (int i = 0; i < s.length(); i++) {
//        if (s[i] == '(') {
//            if (!st.empty() && st.top() == ')')return false;
//            else st.push(s[i]); 
//        }
//        else if (s[i] == ')') {
//            if (st.empty() || st.top()==')')return false;
//            else st.pop();
//        }
//    }
//    if (st.empty()) return true;
//    else return false;
//}

bool solution(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (cnt < 0)return false;
        if (s[i] == '(') cnt++;
        else if (s[i] == ')') cnt--;
    }
    if (cnt==0) return true;
    else return false;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solution("(())()");
	return 0;
}