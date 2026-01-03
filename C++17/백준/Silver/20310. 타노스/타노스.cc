#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <math.h>
#include <cstring>

using namespace std;

char input[501];

void erase(char* arr, bool dir, char target, int num) { // dir 0: from index 0 to greater, 1: from last index to 0 
	int len = strlen(arr);
	char* temparr = new char[len];
	int cur = 0;
	int newlen = 0;
	if (dir) {
		for (int i = 0; i < len; ++i) {
			if (arr[i] != target || cur >= num) {
				temparr[i - cur] = arr[i];
				newlen++;
			}
			else cur++;
		}
		strcpy(arr, temparr);
		arr[len - num] = NULL;
	}
	else {
		for (int i = 0; i < len; ++i) {
			if (arr[len - i - 1] != target || cur >= num) {
				temparr[len - num + cur - i - 1] = arr[len - i - 1];
				newlen++;
			}
			else cur++;
		}
		strcpy(arr, temparr);
		arr[len - num] = NULL;
	}
	delete [] temparr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> input;
	int len = strlen(input);
	int zero_num = 0;
	int one_num = 0;
	for (int i = 0; i < len; ++i) {
		if (input[i] == '0') zero_num++;
		else if (input[i] == '1') one_num++;
	}
	erase(input, false, '0', zero_num / 2);
	erase(input, true, '1', one_num / 2);
	cout << input;
	return 0;
}