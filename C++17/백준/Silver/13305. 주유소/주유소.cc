#include <iostream>
#include <string>
#include <queue>
#include <functional>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, temp, start, res;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	cin >> N;
	long long* disarr = new long long[N];
	for (int i = 0; i < N - 1; ++i) {
		disarr[i] = 0;
		cin >> temp;
		for (int j = 0; j < i + 1; ++j) {
			disarr[j] += temp;
		}
	}
	disarr[N - 1] = 0;
	for (int i = 0; i < N - 1; ++i) {
		cin >> temp;
		pq.push({ temp, i });
	}
	/*
	for (int i = 0; i < N - 1; ++i) {
		cout << "From " << i << ", " << disarr[i] << " is left\n";
	}
	*/
	cin >> temp; // useless
	start = N - 1;
	res = 0;
	while (!pq.empty()) {
		pair<long long, long long> pa = pq.top();
		pq.pop();
		if (start > pa.second) {
			res += pa.first * (disarr[pa.second] - disarr[start]);
			start = pa.second;
		}
	}
	cout << res;
	return 0;
}