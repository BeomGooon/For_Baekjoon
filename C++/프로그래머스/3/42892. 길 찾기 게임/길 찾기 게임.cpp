#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 결국 부모 -> 자식을 연결할 때 특정 노드가 어느 부모의 어느쪽 자식일 것인가?
// 부모 노드에 왼쪽 길이, 오른쪽 최대 길이까지 저장 (생성자 오버로딩)
// 루트 노드는 최소 x값부터 최대 x값까지
// 1. 우선 y 좌표 내림차순으로 pq에 넣음
// 2. 하나씩 꺼내며 struct 생성 및 연결
// 3. 전위, 후위 순회 생성

struct node{
    int left_ind; // 최대 왼쪽 범위
    int right_ind; // 최대 오른쪽 범위
    int self_ind; // 자신의 x좌표
    int number;
    node* left;
    node* right;
    node* parent;
    
    node(int l, int r, int m, int num) { // 루트 노드
        left_ind = l;
        right_ind = r;
        self_ind = m;
        number = num;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    
    node(int l, int r, int m, int num, node* par) { // 자식 노드
        left_ind = l;
        right_ind = r;
        self_ind = m;
        number = num;
        left = NULL;
        right = NULL;
        parent = par;
    }
    
    bool leftside(int ind) {
        return (ind < self_ind && ind >= left_ind);
    }
    bool rightside(int ind) {
        return (ind <= right_ind && ind > self_ind);
    }
};

vector<vector<int>> answer;
vector<int> preorder;
vector<int> postorder;

void pre_dfs(node* ptr) {
    preorder.push_back(ptr->number);
    if (ptr->left) pre_dfs(ptr->left);
    if (ptr->right) pre_dfs(ptr->right);
}

void post_dfs(node* ptr) {
    if (ptr->left) post_dfs(ptr->left);
    if (ptr->right) post_dfs(ptr->right);
    postorder.push_back(ptr->number);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // 변수 및 초기화
    priority_queue<vector<int>> pq;
    vector<node> nodes;
    nodes.reserve(nodeinfo.size());
    vector<node*> leaves;
    vector<node*> next_leaves;
    int x_min = 999999;
    int x_max = 0;
    int t = 1;
    for (vector<int> item : nodeinfo) {
        if (item[0] > x_max) x_max = item[0];
        if (item[0] < x_min) x_min = item[0];
        pq.push({item[1], item[0], t});
        t++;
    }
    
    // 하나씩 꺼내며 struct 생성 및 연결
    nodes.push_back(node(x_min, x_max, pq.top()[1], pq.top()[2]));
    leaves.push_back(&nodes[0]);
    pq.pop();
    int cur_leave_y = pq.top()[0];
    while (!pq.empty()) {
        vector<int> temp = pq.top();
        pq.pop();
        int cury = temp[0];
        int curx = temp[1];
        int num = temp[2];
        if (cury < cur_leave_y) {
            cur_leave_y = cury;
            leaves = next_leaves;
            next_leaves.clear();
        }
        
        for (node* ptr : leaves) {
            if (ptr->leftside(curx)) {
                nodes.push_back(node(ptr->left_ind, ptr->self_ind - 1, curx, num, ptr));
                node* sonptr = &nodes[nodes.size()-1];
                next_leaves.push_back(sonptr);
                ptr->left = sonptr;
                break;
            }
            if (ptr->rightside(curx)) {
                nodes.push_back(node(ptr->self_ind + 1, ptr->right_ind, curx, num, ptr));
                node* sonptr = &nodes[nodes.size()-1];
                next_leaves.push_back(sonptr);
                ptr->right = sonptr;
                break;
            }
        }
    }
    
    /* 디버그용 확인
    for (node &item : nodes) {
        cout << item.number << ' ' << item.left_ind << ' ' << item.right_ind << ' ';
        if (item.left) cout << item.left->number << ' ';
        if (item.right) cout << item.right->number;
        cout << '\n';
    }
    */
    
    // 전위 순회
    pre_dfs(&nodes[0]);
    post_dfs(&nodes[0]);
    
    answer.push_back(preorder);
    answer.push_back(postorder);
    return answer;
}