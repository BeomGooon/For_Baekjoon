#include <iostream>
#include <string>
#include <queue>

using namespace std;

class human {
public:
	int index;
	int weight;
	int height;
	bool operator==(human b) {
		if (weight == b.weight) return true;
		else if (height == b.height) return true;
		else if (weight > b.weight && height < b.height) return true;
		else if (weight < b.weight && height > b.height) return true;
		return false;
	}
	bool operator>(human b) {
		if (weight > b.weight && height > b.height) return true;
		else return false;
	}
	bool operator<(human b) {
		if (weight < b.weight && height < b.height) return true;
		else return false;
	}
	void operator=(human b) {
		index = b.index;
		weight = b.weight;
		height = b.height;
	}
	human() {
		index = -1;
		weight = 0;
		height = 0;
	}
	human(int ind, int wei, int hei) {
		index = ind;
		weight = wei;
		height = hei;
	}
};

void merge(human* ptr, int fir, int sec, int thi, int fou) {
	int i = fir;
	int j = thi;
	human* temp_arr = new human[fou - fir + 1]();
	int temp_ind = 0;
	while (i <= sec && j <= fou) {
		if (ptr[i] > ptr[j]) {
			temp_arr[temp_ind] = ptr[i];
			temp_ind++;
			i++;
		}
		else {
			temp_arr[temp_ind] = ptr[j];
			temp_ind++;
			j++;
		}
	}
	while (i <= sec) {
		temp_arr[temp_ind] = ptr[i];
		temp_ind++;
		i++;
	}
	while (j <= fou) {
		temp_arr[temp_ind] = ptr[j];
		temp_ind++;
		j++;
	}
	for (int k = 0; k < temp_ind; k++) {
		ptr[fir + k] = temp_arr[k];
	}
}

void merge_sort(human* ptr, int start, int end) {
	int num = (end - start + 1)/2;
	if (start != end) {
		merge_sort(ptr, start, start + num - 1);
		merge_sort(ptr, start + num, end);
	}
	merge(ptr, start, start + num - 1, start + num, end);
}

int is_vowel(char input) {
	if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string inp;
	bool loop_flag = true;
	bool vowel_flag = true;
	bool three_flag = true;
	bool double_flag = true;
	char last_char = '0';
	int last_vowel = -1; // 0: consonant, 1: vowel
	int last_last_vowel = -1;
	int len;
	while (loop_flag) {
		vowel_flag = false;
		three_flag = true;
		double_flag = true;
		last_char = '0';
		last_vowel = -1;
		last_last_vowel = -1;
		cin >> inp;
		if (inp == "end") break;
		len = inp.length();
		for (int i = 0; i < len; i++) {
			int temp = is_vowel(inp[i]);
			if (vowel_flag == false && temp) vowel_flag = true;
			if (last_vowel == last_last_vowel && last_vowel == temp) three_flag = false;
			if (last_char == inp[i] && last_char != 'e' && last_char != 'o') double_flag = false;
			last_last_vowel = last_vowel;
			last_vowel = temp;
			last_char = inp[i];
		}
		if (vowel_flag && three_flag && double_flag) {
			cout << '<' << inp << "> is acceptable.\n";
		}
		else {
			cout << '<' << inp << "> is not acceptable.\n";
		}
	}
	return 0;
}