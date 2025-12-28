#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
#include <stack>
using namespace std;

char arr[10000000];

long long to_string(char ptr[], long long num) {
	stack<char> st;
	while (num) {
		st.push(num % 10 + '0');
		num = num / 10;
	}
	int ind = 0;
	while (!st.empty()) {
		ptr[ind] = st.top();
		st.pop();
		ind++;
	}
	return ind;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long idx, num;
	string input;
	cin >> input;
	num = 0;
	idx = 0;
	while (idx < input.length()) {
		num++;
		long long len = to_string(arr, num);
		// cout << "arr: " << arr << '\n';
		// cout << "last: " << len << '\n';
		for (int i = 0; i < len; ++i) {
			if (idx < input.length() && arr[i] == input[idx]) {
				idx++;
			}
		}
	}
	cout << num;
	return 0;
}