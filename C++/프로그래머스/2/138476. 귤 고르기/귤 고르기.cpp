#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    priority_queue<vector<int>> max_heap;
    unordered_map<int, int> dict;
    
    long long n = tangerine.size();
    for (long long i = 0; i < n; i++) {
        int temp = tangerine[i];
        if (dict.find(temp) == dict.end()) {
            dict[temp] = 1;
        }
        else {
            dict[temp] += 1;
        }
    }
    
    for (const auto& pair : dict) {
        vector<int> v;
        v.push_back(pair.second);
        v.push_back(pair.first);
        max_heap.push(v);
    }
    
    int cur = 0;
    while (cur < k) {
        vector<int> temp = max_heap.top();
        max_heap.pop();
        cur += temp[0];
        answer++;
    }
    
    return answer;
}