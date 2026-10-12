#include <string>
#include <vector>

using namespace std;

//start지점부터 시작할 때 u의 끝 부분 index를 반환
int find_u(string &inp, int start) {
    int N = inp.size();
    int open_num = 0;
    int close_num = 0;
    for (int i = start; i < N; i++) {
        if (inp[i] == '(') open_num++;
        else close_num++;
        if (open_num == close_num) return i;
    }
    return (N-1);
}

bool is_correct(string &inp) {
    int open_num = 0;
    for (char item : inp) {
        if (item == '(') open_num++;
        else {
            if (open_num == 0) return false;
            else open_num--;
        }
    }
    if (open_num == 0) return true;
    else return false;
}

string dfs(string inp, int u_start) {
    // 1. u, v로 분리
    int u_end = find_u(inp, u_start);
    string u_str = inp.substr(u_start, u_end - u_start + 1);
    string v_str = "";
    if (u_end != inp.size() - 1) v_str = dfs(inp, u_end + 1);
    
    // u가 올바른지 확인
    if (is_correct(u_str)) return (u_str + v_str);
    else {
        string output = "(";
        output += v_str;
        output += ')';
        for (int i = 1; i < u_str.size() - 1; i++) {
            if (u_str[i] == '(') output += ')';
            else output += '(';
        }
        return output;
    }
}

string solution(string p) {
    int start = 0;
    
    if (is_correct(p)) return p;
    
    string answer = dfs(p,0);
    return answer;
}