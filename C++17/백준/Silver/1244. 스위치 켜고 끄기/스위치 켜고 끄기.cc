#include <iostream>
#include <queue>
using namespace std;

void switch_men(bool* ptr, int inp, int N) {
	int temp = inp;
	while (temp <= N) {
		ptr[temp] = (ptr[temp] ^ 0x01);
		temp += inp;
	}
}

void switch_women(bool* ptr, int inp, int N) {
	int len = 0;
	while (inp > len && inp + len <= N && ptr[inp - len] == ptr[inp + len]) {
		if (len) {
			ptr[inp - len] = (ptr[inp - len] ^ 0x01);
			ptr[inp + len] = (ptr[inp + len] ^ 0x01);
		}
		else ptr[inp] = (ptr[inp] ^ 0x01);
		len++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, students_num, gender, inp;
	bool* arr;
	cin >> N;
	arr = new bool[N + 1];
	for (int i = 1; i < N + 1; ++i) {
		cin >> arr[i];
	}
	cin >> students_num;
	for (int i = 0; i < students_num; ++i) {
		cin >> gender >> inp;
		if (gender == 1) switch_men(arr, inp, N);
		else switch_women(arr, inp, N);
	}
	for (int i = 1; i <= N; i++) {
		if (i % 20 == 0) {
			cout << arr[i] << '\n';
		}
		else cout << arr[i] << ' ';
	}
	return 0;
}