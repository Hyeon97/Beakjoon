//오픈채팅방
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string>m;
	vector<pair<string, string>> temp;
	string st, uuid, uid;
	for (int i = 0; i < record.size(); i++) {
		stringstream ss;
		ss.str(record[i]);
		ss >> st;
		if (!st.compare("Enter")) {
			ss >> uuid;
			ss >> uid;
			if (m.find(uuid) == m.end()) {//새로운 유저 인경우 유저값 추가
				m.insert({ uuid, uid });
			}
			//기존유저인경우 정보 갱신
			else if (m[uuid].compare(uid)) {
				m[uuid] = uid;
			}
			temp.push_back({ st,uuid });
		}
		else if (!st.compare("Leave")) {
			ss >> uuid;
			temp.push_back({ st,uuid });
		}
		else {
			ss >> uuid;
			ss >> uid;
			/*m.erase(uuid);
			m.insert({ uuid,uid });*/
			m[uuid] = uid;
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		string s;
		if (!temp[i].first.compare("Enter")) {
			s = m[temp[i].second] + "님이 들어왔습니다.";
			answer.push_back(s);
		}
		else if (!temp[i].first.compare("Leave")) {
			s = m[temp[i].second] + "님이 나갔습니다.";
			answer.push_back(s);
		}
	}
	return answer;
}