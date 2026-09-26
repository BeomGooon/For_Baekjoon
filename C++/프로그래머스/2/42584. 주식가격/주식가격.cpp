#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st; // {실제 값, 들어온 인덱스}를 저장
    int index = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++) answer.push_back(0);
    for (int item : prices) {
        while (!st.empty() && st.top().first > item) {
            answer[st.top().second] = index - st.top().second;
            
            st.pop();
        }
        st.push({item, index});
        index++;
    }
    
    while (!st.empty()) {
        answer[st.top().second] = n - 1 - st.top().second;
        st.pop();
    }
    
    return answer;
}