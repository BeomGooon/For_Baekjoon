#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>

using namespace std;

int arr[1001][2]; // second index 0: left, 1: right
int peak_index;
int peak_height;
int start_point;
int end_point;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	peak_height = 0;
	start_point = 1001;
	end_point = 0;
	for (int i = 0; i < N; ++i) {
		int L, H;
		cin >> L >> H;
		if (H > peak_height) { // new peak
			peak_index = L;
			peak_height = H;
		}
		if (L < start_point) {
			start_point = L;
		}
		if (L > end_point) {
			end_point = L;
		}
		for (int i = L; i < 1001; ++i) {
			if (arr[i][0] < H) arr[i][0] = H;
		}
		for (int i = L; i >= 0; --i) {
			if (arr[i][1] < H) arr[i][1] = H;
		}
	}
	int result = 0;
	for (int i = start_point; i < peak_index; ++i) {
		result += arr[i][0];
		// cout << "index " << i << ": " << arr[i][0] << '\n';
	}
	for (int i = peak_index; i <= end_point; ++i) {
		result += arr[i][1];
		// cout << "index " << i << ": " << arr[i][1] << '\n';
	}
	cout << result;
	return 0;
}