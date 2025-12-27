#include <iostream>
#include <string>
#include <queue>
#include <functional>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, last, next, res, temp;
	res = -1;
	cin >> N >> M;
	last = 0;
	cin >> next;
	res = next - last;
	last = next;
	for (int i = 1; i < M; ++i) {
		cin >> next;
		temp = (next - last + 1) / 2;
		if (res < temp) res = temp;
		last = next;
	}
	next = N;
	if (res < next - last) res = next - last;
	cout << res;
	return 0;
}