#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>

using namespace std;

int N, H, M; // N: width, H: Height, M: number of horizontal lines input

bool check(vector<int> arr) { // check if this set of horizontal lines satisfies condition
	int temp[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < H; ++i) {
		int bit = 0x01;
		for (int j = 1; j < N; ++j) {
			if (bit & arr[i]) {
				int abc = temp[j];
				temp[j] = temp[j - 1];
				temp[j - 1] = abc;
			}
			bit <<= 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (temp[i] != i) return false;
	}
	return true;
}

vector<int> get_available_sets(vector<int> arr) { // find available sets of horizontal lines depending on current state
	vector<int> result = {};
	for (int i = 0; i < H; ++i) {
		int temp = 0;
		for (int j = 0; j < N - 1; ++j) {
			temp += (0x01 << j);
		}
		int temp2 = (arr[i] | (arr[i] << 1) | (arr[i] >> 1));
		temp = (temp & (~(temp & temp2)));
		result.push_back(temp);
	}
	return result;
}

bool find_sets(vector<int> arr, int num, int lasty, int lastx) { // recursive which find brute-force answer. num: left number of horizontal to place
	if (num == 0) return check(arr);
	else {
		vector<int> available_sets = get_available_sets(arr);
		vector<int> for_input = arr;
		for (int i = lasty; i < H; ++i) {
			int temp = 0x01;
			int j = 0;
			if (i == lasty) {
				j = lastx;
				temp <<= lastx;
			}
			for (; j < N - 1; ++j) {
				if (temp & available_sets[i]) {
					for_input[i] += temp;
					// cout << for_input[i] << '\n';
					if (find_sets(for_input, num - 1, i, j + 1)) return true;
					for_input[i] -= temp;
				}
				temp <<= 1;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> H;
	vector<int> init_state;
	for (int i = 0; i < H; ++i) {
		init_state.push_back(0);
	}
	for (int i = 0; i < M; ++i) {
		int y, x;
		cin >> y >> x;
		init_state[y - 1] += (0x01 << (x - 1));
	}

	/*
	cout << "init_state: " << init_state[0] << '\n';
	cout << "check: " << check(init_state) << '\n';
	vector<int> ttt = get_available_sets(init_state);
	for (int i = 0; i < H; ++i) {
		cout << ttt[i]<< '\n';
	}
	*/

	int result = -1;
	for (int i = 0; i < 4; ++i) {
		if (find_sets(init_state, i, 0, 0)) {
			result = i;
			break;
		}
	}
	cout << result;
	return 0;
}