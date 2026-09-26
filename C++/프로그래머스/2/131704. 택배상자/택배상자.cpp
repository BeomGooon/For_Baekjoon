#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
bool visited[1000001];

int solution(vector<int> order) {
    int answer = 1;
    int n = order.size();
    vector<int> temp = order;
    stack<int> st;
    
    // '컨테이너 속 위치'로 저장돼있던 내용물을 실제 컨테이너 순서로 변경
    for (int i = 0; i < n; i++) {
        order[temp[i] - 1] = i + 1;
    }
    
    for (int item : order) {
        while (!st.empty() && st.top() == answer) { // 스택에서 하나씩 꺼내기
            st.pop();
            answer++;
        }
        if (visited[answer]) break; // 스택에서 꺼낼 거 다 꺼냈음에도 불구하고 방문했던 item이 스택에 존재한 경우
        if (item == answer) { // order에서 맞는 item을 찾았을 때
            answer++;
        }
        else { // item이 맞지 않는 경우 => 스택에 추가
            st.push(item);
        }
        
        
        visited[item] = true;
    }
    while (!st.empty() && st.top() == answer) {
        st.pop();
        answer++;
    }
    
    return answer - 1;
}