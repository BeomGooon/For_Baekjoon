#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string enter_msg = "님이 들어왔습니다.";
string leave_msg = "님이 나갔습니다.";

vector<string> split(const string &inp) {
    vector<string> output;
    string temp = "";
    for (char c : inp) {
        if (c != ' ') {
            temp += c;
        }
        else {
            output.push_back(temp);
            temp = "";
        }
    }
    output.push_back(temp);
    return output;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> split_vec;
    unordered_map<string, string> id_dict;
    
    // record에서 하나씩 꺼내 id-이름 저장, split한 결과물 split_vec에 저장
    for (string item : record) {
        vector<string> temp = split(item);
        if (temp[0] == "Enter" || temp[0] == "Change") {
            id_dict[temp[1]] = temp[2];
        }
        split_vec.push_back(temp);
    }
    
    // split_vec에서 하나씩 꺼내서 answer에 추가
    for (vector<string> vec : split_vec) {
        if (vec[0] == "Enter") {
            answer.push_back(id_dict[vec[1]] + enter_msg);
        }
        else if (vec[0] == "Leave") {
            answer.push_back(id_dict[vec[1]] + leave_msg);
        }
    }
    
    return answer;
}