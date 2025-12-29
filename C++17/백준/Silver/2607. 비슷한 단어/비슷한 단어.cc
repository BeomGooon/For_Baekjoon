#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>

using namespace std;

int first_config[26];
int comp_config[26];

void make_config(int arr[], string str) {
	int n = str.length();
	for (int i = 0; i < n; ++i) {
		arr[str[i]-'A']++;
	}
}

void clear_config(int arr[]) {
	for (int i = 0; i < 26; ++i) {
		arr[i] = 0;
	}
}

bool same_config(int arr1[], int arr2[]) {
	for (int i = 0; i < 26; ++i) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

bool similar_config(int arr1[], int arr2[]) {
	bool left_is_bigger;
	bool first = true;
	bool last = false;
	for (int i = 0; i < 26; ++i) {
		int temp = arr1[i] - arr2[i];
		if (abs(temp) > 1) return false;
		else if (temp == 1) {
			if (first) {
				left_is_bigger = true;
				first = false;
			}
			else if (last || left_is_bigger) return false;
			else if (!left_is_bigger) {
				last = true;
			}
		}
		else if (temp == -1) {
			if (first) {
				left_is_bigger = false;
				first = false;
			}
			else if (last || !left_is_bigger) return false;
			else if (left_is_bigger) {
				last = true;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, result;
	string inp;
	cin >> N;
	result = 0;
	cin >> inp;
	make_config(first_config, inp);
	for (int i = 1; i < N; ++i) {
		cin >> inp;
		make_config(comp_config, inp);
		// cout << same_config(first_config, comp_config) << ' ' <<  similar_config(first_config, comp_config) << '\n';
		result += (same_config(first_config, comp_config) || similar_config(first_config, comp_config));
		clear_config(comp_config);
	}
	cout << result;
	return 0;
}