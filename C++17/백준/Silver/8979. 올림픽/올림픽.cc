#include <iostream>
#include <queue>
using namespace std;

struct country {
	int name;
	int gold;
	int silver;
	int bronze;
	void operator=(const country c2) {
		name = c2.name;
		gold = c2.gold;
		silver = c2.silver;
		bronze = c2.bronze;
	}
	country(int n, int a, int b, int c) {
		name = n;
		gold = a;
		silver = b;
		bronze = c;
	}
	country() {
		name = -1;
		gold = 0;
		silver = 0;
		bronze = 0;
	}
};

bool operator<(const country c1, const country c2) {
	if (c1.gold < c2.gold) return true;
	else if (c1.gold == c2.gold) {
		if (c1.silver < c2.silver) return true;
		else if (c1.silver == c2.silver) {
			if (c1.bronze < c2.bronze) return true;
		}
	}
	return false;
}

bool operator==(const country c1, const country c2) {
	if (c1.gold == c2.gold && c1.silver == c2.silver && c1.bronze == c2.bronze) return true;
	return false;
}


void merge(country* fir, country* sec, int num) {
	int i = 0;
	int j = 0;
	bool flag = true;
	country* temp = new country[2 * num];
	int temp_ind = 0;
	while (i < num && j < num) {
		if (fir[i] < sec[j]) {
			temp[temp_ind] = fir[i];
			i++;
			temp_ind++;
		}
		else {
			temp[temp_ind] = sec[j];
			j++;
			temp_ind++;
		}
	}
	while (i < num) {
		temp[temp_ind] = fir[i];
		temp_ind++;
		i++;
	}
	while (j < num) {
		temp[temp_ind] = sec[j];
		j++;
		temp_ind++;
	}
	for (int k = 0; k < temp_ind; k++) {
		fir[k] = temp[k];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	country* arr = new country[N];
	queue<country*> que;
	for (int i = 0; i < N; i++) {
		int ctr, gld, sil, bro;
		cin >> ctr >> gld >> sil >> bro;
		arr[i] = country(ctr, gld, sil, bro);
		que.push(arr + i);
	}
	while (que.size() != 1) {
		int tempsize = que.size();
		for (int i = 0; i < tempsize; i += 2) {
			if (i != tempsize - 1) {
				country* first = que.front();
				que.pop();
				country* second = que.front();
				que.pop();
				int num = second - first;
				merge(first, second, num);
				que.push(first);
			}
			else {
				country* temp_ctr_ptr = que.front();
				que.pop();
				que.push(temp_ctr_ptr);
			}
		}
	}
	int res = 0;
	for (int i = N-1; i >= 0; i--) {
		if (arr[i].name == K) {
			res = N - i;
		}
	}
	while (arr[N - res] == arr[N - res + 1]) {
		res--;
	}
	cout << res;
	return 0;
}