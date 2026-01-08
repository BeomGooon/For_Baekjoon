#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;

int rank_score[300];
priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> rooms[300];
int p, m, num_room;

int check(int inp) { // returns available index of room. if new room is needed, return the index of new room
	for (int i = 0; i < num_room; ++i) {
		if (rooms[i].size() < m && inp >= rank_score[i] - 10 && inp <= rank_score[i] + 10) return i;
	}
	return num_room;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p >> m;
	num_room = 0;
	for (int i = 0; i < p; ++i) {
		int temp1, cur_room;
		string temp2;
		cin >> temp1 >> temp2;
		cur_room = check(temp1);
		if (cur_room == num_room) {
			num_room++;
			rank_score[cur_room] = temp1;
		}
		rooms[cur_room].push({ temp2, temp1 });
	}
	for (int i = 0; i < num_room; ++i) {
		if (rooms[i].size() < m) cout << "Waiting!\n";
		else cout << "Started!\n";
		while (!rooms[i].empty()) {
			pair<string, int> temp_pair = rooms[i].top();
			cout << temp_pair.second << ' ' << temp_pair.first << '\n';
			rooms[i].pop();
		}
	}
	return 0;
}