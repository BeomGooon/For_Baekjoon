#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cctype>

using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cur_cache_num = 0;
    int n = cities.size();
    unordered_map<string, int> dict; // 도시 이름, 가장 최근 접근한 시점 저장
    
    // 모두 소문자로 변환
    for (string &str : cities) {
        for (char &c : str) {
            c = tolower(c);
        }
    }    
    
    // cacheSize가 0인 경우: 그냥 5 곱하면 됨
    if (cacheSize == 0) return 5 * n;
    
    // 도시 이름 읽으면서 캐시에 저장
    for (int i = 0; i < n; i++) {
        string temp = cities[i];
        if (dict.find(temp) != dict.end()) {
            dict[temp] = i;
            answer++;
        }
        else if (cur_cache_num < cacheSize) {
            dict[temp] = i;
            cur_cache_num = min(cur_cache_num + 1, cacheSize);
            answer += 5;
        }
        else {
            // LRU에 의해 제거할 string 구함
            string word_remove;
            int mi = 100000000;
            for (const auto &pair : dict) {
                if (mi > pair.second) {
                    word_remove = pair.first;
                    mi = pair.second;
                }
            }
            dict.erase(word_remove);
            dict[temp] = i;
            answer += 5;
        }
    }
    return answer;
}