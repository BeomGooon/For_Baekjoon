#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    unordered_map<int, bool> dict_asc;
    unordered_map<int, bool> dict_desc;
    vector<int> type_asc;
    vector<int> type_desc;
    int cur_type_asc = 0;
    int cur_type_desc = 0;
    
    // 0~n-1, n-1~0 순으로 읽어가며 현재까지의 토핑 가짓수 저장
    for (int i = 0; i < n; i++) {
        int temp = topping[i];
        if (dict_asc.find(temp) == dict_asc.end()) {
            dict_asc[temp] = true;
            cur_type_asc++;
        }
        type_asc.push_back(cur_type_asc);
    }
    for (int i = n-1; i >= 0; i--) {
        int temp = topping[i];
        if (dict_desc.find(temp) == dict_desc.end()) {
            dict_desc[temp] = true;
            cur_type_desc++;
        }
        type_desc.push_back(cur_type_desc);
    }
    
    // 이제 같은 index 기준 type_asc와 type_desc의 개수가 같은지 확인
    for (int i = 0; i < n - 1; i++) {
        // printf("%d: %d, %d\n", i, type_asc[i], type_desc[n-i-2]);
        if (type_asc[i] == type_desc[n - i - 2]) answer++;
    }
    
    return answer;
}