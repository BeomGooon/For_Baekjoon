#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>

using namespace std;

const long long max_number = 1000000;
bool prime_arr[max_number + 1];
long long prime_square_arr[max_number + 1];
bool result_arr[max_number + 1];
int prime_square_num = 0;

void make_prime_array() {
	for (long long i = 2; i < max_number; ++i) {
		if (!prime_arr[i]) {
			long long cur = i;
			prime_square_arr[prime_square_num] = cur * cur;
			++prime_square_num;
			while (cur <= max_number) {
				prime_arr[cur] = true;
				cur += i;
			}
		}
	}
}

void check_prime_square(long long start, long long end) { // returns true if not devided by prime_square numbers
	long long temp;
	for (int i = 0; i < prime_square_num; ++i) {
		temp = prime_square_arr[i];
		long long cur = ((start + temp - 1) / temp) * temp;
		while (cur < end + 1) {
			if (cur >= start) result_arr[cur - start] = true;
			cur += temp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	make_prime_array();
	// cout << prime_square_num;
	long long inp_min, inp_max, result;
	cin >> inp_min >> inp_max;
	check_prime_square(inp_min, inp_max);
	result = 0;
	for (long long i = inp_min; i < inp_max + 1; ++i) {
		result += (result_arr[i - inp_min] ^ 0x01);
	}
	cout << result;
	return 0;
}