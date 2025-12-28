#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
#include <stack>
using namespace std;

char arr[20002];
bool used[20002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, res, start;
	res = 0;
	start = 0;
	cin >> N >> K >> arr;
	for (int i = 0; i < N; ++i) {
		if (arr[i] == 'P') {
			for (int j = max(start, i - K); j < i + K + 1; ++j) {
				if ((arr[j] == 'H') && !used[j]) {
					// cout << j << " hamburger is eaten by " << i << " person\n";
					used[j] = true;
					res++;
					start = j + 1;
					j = i + K;
				}
			}
		}
	}
	cout << res;
	return 0;
}