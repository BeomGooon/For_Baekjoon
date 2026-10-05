#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

long long num_list[1001];
vector<pair<int,int>> mul_pair = {{4, 2}, {4, 3}, {3, 2}};

long long solution(vector<int> weights) {
    // 변수 및 초기화
    long long answer = 0;
    sort(weights.begin(), weights.end()); // 오름차순 정렬
    unordered_map<int, bool> dict; // 중복 제거한 사람들 무게
    vector<int> lis; //중복 제거한 사람들 무게
    
    // 중복 제거 및 개수 확인
    for (int item : weights) {
        num_list[item]++;
        dict[item] = true;
    }
    
    // lis에 추가 및 정렬
    for (const auto &pair : dict) lis.push_back(pair.first);
    sort(lis.begin(), lis.end());
    
    // 조합 확인
    int n = lis.size();
    for (int i = 0; i < n; i++) {
        int fir_int = lis[i];
        int sec_int;
        answer += (num_list[fir_int] - 1) * num_list[fir_int] / 2;
        for (int j = i + 1; j < n; j++) {
            sec_int = lis[j];
            for (pair temp_pair : mul_pair) {
                if (fir_int * temp_pair.first == sec_int * temp_pair.second) {
                    answer += num_list[fir_int] * num_list[sec_int];
                    break;
                }
            }
        }
    }
    
    return answer;
}