#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct node {
    int index;
    vector<int> next_list;
    
    node() {
        index = 0;
    }
    node(int inp) {
        index = inp;
    }
};

// i1, i2에서 시작하는 노드 개수 구하기
int bfs(vector<node> &node_vec, vector<bool> &false_map, int i1, int i2) {
    // 변수 및 초기화
    queue<int> que;
    vector<bool> touched = false_map;
    int output;
    int from_i1 = 1;
    int from_i2 = 1;
    
    // i1에서 출발
    touched[i1] = true;
    for (int item : node_vec[i1].next_list) {
        if (item != i2) {
            que.push(item);
            touched[item] = true;
        }
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        from_i1 += 1;
        for (int item : node_vec[temp].next_list) {
            if (!touched[item]) {
                que.push(item);
                touched[item] = true;
            }
        }
    }
    
    // i2에서 출발
    touched[i2] = true;
    for (int item : node_vec[i2].next_list) {
        if (item != i1) {
            que.push(item);
            touched[item] = true;
        }
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        from_i2 += 1;
        for (int item : node_vec[temp].next_list) {
            if (!touched[item]) {
                que.push(item);
                touched[item] = true;
            }
        }
    }
    
    output = abs(from_i1 - from_i2);
    return output;
}

int solution(int n, vector<vector<int>> wires) {
    // 변수 및 초기화
    int answer = 9999;
    vector<node> node_vec;
    vector<bool> touched_map;
    
    // touched_map 초기화
    for (int i = 0; i <= n; i++) {
        touched_map.push_back(false);
        node_vec.push_back(node(i));
    }
    
    // wires에서 가져와서 연결
    for (vector<int> item : wires) {
        int i1 = item[0];
        int i2 = item[1];
        node_vec[i1].next_list.push_back(i2);
        node_vec[i2].next_list.push_back(i1);
    }
    
    // 하나씩 빼면서 확인
    for (vector<int> item : wires) {
        int i1 = item[0];
        int i2 = item[1];
        int temp = bfs(node_vec, touched_map, i1, i2);
        if (answer > temp) answer = temp;
    }
    
    return answer;
}