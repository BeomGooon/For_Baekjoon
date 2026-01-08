#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, int> note;
	unordered_map<string, int> blog;
	int N, M;
	string temp, templine;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		note[temp] = 1;
	}
	const int note_size = note.size();
	for (int i = 0; i < M; ++i) {
		cin >> templine;
		stringstream ss(templine);
		while (getline(ss, temp, ',')) {
			if (note.find(temp) != note.end()) {
				blog[temp] = 1;
			}
		}
		int blog_size = blog.size();
		cout << (note_size - blog_size) << '\n';
	}
	return 0;
}