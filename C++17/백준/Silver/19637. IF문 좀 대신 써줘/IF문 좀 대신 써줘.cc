#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>

using namespace std;

pair<string, long long> arr[100000];

string binary_search(int start, int end, long long target) {
	int middle = (start + end) / 2;
	if (start == end) return arr[start].first;
	if (target <= arr[middle].second) {
		return binary_search(start, middle, target);
	}
	else return binary_search(middle + 1, end, target);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < M; ++i) {
		long long temp;
		cin >> temp;
		cout << binary_search(0, N - 1, temp) << '\n';
	}
	return 0;
}