#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
#include <stack>
using namespace std;

long long arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<long long> pq;
	stack<long long> st;
	long long N, temp, M, fir, sec;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		pq.push(temp);
	}
	cin >> M;
	fir = pq.top();
	pq.pop();
	st.push(fir);
	temp = 1;
	while (!pq.empty()) {
		sec = pq.top();
		pq.pop();
		st.push(sec);
		arr[fir] = temp;
		temp++;
		fir = sec;
	}
	arr[fir] = temp;
	fir = 0;
	long long res = 0;
	long long sum = 0;
	while (!st.empty()) {
		sec = st.top();
		// cout << "current top is " << sec << '\n';
		st.pop();
		sum += (sec - fir) * arr[sec];
		// cout << "current sum is " << sum << '\n';
		if (sum > M) {
			res = sec - (sum - M + arr[sec] - 1) / arr[sec];
			break;
		}
		else if (st.empty()) {
			cout << sec;
			return 0;
		}
		fir = sec;
	}
	cout << res;
	return 0;
}