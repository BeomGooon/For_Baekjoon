#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int enemy_num = enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    int pq_num = 0;
    int cur = 0;
    
    for (int i = 0; i < enemy_num; i++) {
        int temp = enemy[i];
        if (pq_num < k) {
            pq.push(temp);
            pq_num++;
        }
        else {
            if (pq.top() < temp) {  // 교체 후 더함
                cur += pq.top();
                pq.pop();
                pq.push(temp);
            }
            else { // temp를 더함
                cur += temp;
            }
            if (cur > n) { // 완료된 값 return
                return i;
            }
        }
    }
    
    return enemy_num;
}