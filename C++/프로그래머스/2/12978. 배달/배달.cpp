#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int index;
    vector<int> next_list; // 연결된 인덱스 저장
    vector<int> dis_list; // 거리 저장 (next_list와 동일한 인덱스 순서 유지)
    
    node(int inp) {
        index = inp;
    }
};

struct for_queue {
    int node;
    int distance;
    for_queue(int nd, int dis) {
        node = nd;
        distance = dis;
    }
    
    bool operator<(const for_queue &another) const {
        return (this->distance > another.distance);
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    // 변수 및 초기화
    int answer = 0;
    vector<bool> touched;
    vector<node> vec_node;
    priority_queue<for_queue> que; // {현재 노드, 현재까지 거리} 저장
    for (int i = 0; i < N + 1; i++) {
        vec_node.push_back(node(i));
        touched.push_back(false);
    }
    
    // road 내용물 읽어서 노드 연결
    for (vector<int> item : road) {
        int i1 = item[0];
        int i2 = item[1];
        int dis = item[2];
        vec_node[i1].next_list.push_back(i2);
        vec_node[i2].next_list.push_back(i1);
        vec_node[i1].dis_list.push_back(dis);
        vec_node[i2].dis_list.push_back(dis);
    }
    
    // bfs
    que.push({1,0});
    while (!que.empty()) {
        for_queue temp = que.top();
        que.pop();
        int cur_ind = temp.node;
        int cur_dis = temp.distance;
        int next_num = vec_node[cur_ind].next_list.size();
        if (touched[cur_ind]) continue;
        else {
            touched[cur_ind] = true;
            answer++;
        }
        for (int i = 0; i < next_num; i++) {
            int next_ind = vec_node[cur_ind].next_list[i];
            int next_dis = vec_node[cur_ind].dis_list[i];
            if (next_dis + cur_dis <= K && !touched[next_ind]) {
                que.push(for_queue(next_ind, next_dis + cur_dis));
            }
        }
    }

    return answer;
}