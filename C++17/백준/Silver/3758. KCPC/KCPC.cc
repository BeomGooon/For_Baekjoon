#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>

using namespace std;

int answer_times[101];
int last_answer[101];
int scores[101][101];
int total_score[101];

void clear_all() {
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			scores[i][j] = 0;
		}
		answer_times[i] = 0;
		last_answer[i] = 0;
		total_score[i] = 0;
	}
}

bool compare_team(int me, int them) { // True: first team is higher, False: second team is higher
	if (total_score[me] == total_score[them]) {
		if (answer_times[me] == answer_times[them]) {
			return (last_answer[me] < last_answer[them]);
		}
		else return (answer_times[me] < answer_times[them]);
	}
	else return (total_score[me] > total_score[them]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, k, t, m, res; // T, test cases, n: teams, k: questions, t: your team ID, m: logs
	cin >> T;
	for (int i = 0; i < T; ++i) { // i: each test case
		cin >> n >> k >> t >> m;
		res = 1;
		for (int j = 1; j < m + 1; ++j) { // j: log time
			int temp_team, temp_ques, temp_score;
			cin >> temp_team >> temp_ques >> temp_score;
			answer_times[temp_team]++;
			last_answer[temp_team] = j;
			total_score[temp_team] -= scores[temp_team][temp_ques];
			scores[temp_team][temp_ques] = max(scores[temp_team][temp_ques], temp_score);
			total_score[temp_team] += scores[temp_team][temp_ques];
		}
		for (int j = 1; j < n + 1; ++j) {
			if (j != t && compare_team(j, t)) {
				// cout << "team " << j << " is higher than team " << t << '\n';
				// cout << "team " << j << " has scored " << total_score[j] << '\n';
				// cout << "team " << t << " has scored " << total_score[t] << '\n';
				res++;
			}
		}
		cout << res << '\n';
		clear_all();
	}
	return 0;
}