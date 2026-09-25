#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    priority_queue<int, vector<int>, greater<int>> pq; // 이전까지 읽어왔던 숫자들
    unordered_map<int, vector<int>> dict; // 실제 숫자 - index 형식의 dictionary
    
    for (int i = 0; i < n; i++) answer.push_back(-1);
    
    for (int i = 0; i < n; i++) {
        int item = numbers[i];
        
        // pq에서 하나씩 꺼내서 작은 거 있는지 확인
        while (!pq.empty()) {
            if (pq.top() < item) {
                int to_remove = pq.top();
                for (int index : dict[to_remove]) {
                    answer[index] = item;
                }
                dict.erase(to_remove);
                pq.pop();
            }
            else if (pq.top() > item) {
                pq.push(item);
                break;
            }
            else if (pq.top() == item) break;
        }
        
        // pq가 비워져 있다면 추가
        if (pq.empty()) pq.push(item);
        
        // dict에 자기 채워넣기
        if (dict.find(item) != dict.end()) dict[item].push_back(i);
        else dict[item] = {i};
    }
    
    return answer;
}