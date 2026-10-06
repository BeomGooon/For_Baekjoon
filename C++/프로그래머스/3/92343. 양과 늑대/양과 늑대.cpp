#include <vector>
using namespace std;

int answer = 0;
vector<vector<int>> child;
vector<int> g_info;
vector<bool> seen;

void dfs(int mask) {
    if (seen[mask]) return;
    seen[mask] = true;

    int sheep = 0, wolf = 0, n = g_info.size();
    for (int i = 0; i < n; i++)
        if (mask >> i & 1) (g_info[i] ? wolf : sheep)++;
    if (sheep <= wolf) return;
    answer = max(answer, sheep);

    // 방문한 노드들의 자식 중 아직 안 간 곳으로 확장
    for (int i = 0; i < n; i++) if (mask >> i & 1)
        for (int c : child[i])
            if (!(mask >> c & 1)) dfs(mask | (1 << c));
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    g_info = info;
    child.assign(n, {});
    seen.assign(1 << n, false);
    for (auto &e : edges) child[e[0]].push_back(e[1]);  // 부모→자식 단방향이면 충분
    dfs(1);  // 루트(0번)만 방문한 상태
    return answer;
}