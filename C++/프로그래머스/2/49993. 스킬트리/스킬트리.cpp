#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int sequence[26]; // 특정 스킬의 순서를 저장한 array

int solution(string skill, vector<string> skill_trees) {
    // 필수 변수 초기화
    int answer = 0;
    fill(sequence, sequence + 26, -1);
    int n = skill.size();
    
    // skill을 읽으면서 sequence에 추가
    for (int i = 0; i < n; i++) {
        sequence[skill[i] - 'A'] = i;
    }
    
    // skill_trees의 스킬들을 하나씩 읽으면서 스킬트리가 가능한지 확인
    for (string cur_skill_tree : skill_trees) {
        int next_sequence = 0; // 다음으로 읽을 스킬 순서
        for (char c : cur_skill_tree) {
            int int_c = c - 'A';
            if (sequence[int_c] != -1 && sequence[int_c] != next_sequence) {
                // cout << "not: " << cur_skill_tree << '\n';
                answer--;
                break;
            }
            else if (sequence[int_c] == next_sequence) next_sequence++;
        }
        answer++;
    }
    
    return answer;
}