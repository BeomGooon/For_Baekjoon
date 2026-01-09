#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>

using namespace std;

int result[10];
int left_arr[10]; // number of people who is left and appeared(= smaller)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int temp, cur;
		cin >> temp;
		for (int j = 0; j < N; ++j) {
			if (result[j] == 0 && left_arr[j] + temp == j) {
				cur = j;
				result[cur] = i + 1;
				break;
			}
		}
		for (int j = cur + 1; j < N; ++j) left_arr[j]++;
	}
	for (int i = 0; i < N; ++i) cout << result[i] << ' ';
	/*
	cout << '\n';
	for (int i = 0; i < N; ++i) cout << left_arr[i] << ' ';
	*/
	return 0;
}