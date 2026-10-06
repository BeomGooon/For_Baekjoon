#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int gcd(vector<int> &inp) {
    int n = inp.size();
    int temp = inp[0];
    for (int i = 1; i < n; i++) {
        temp = gcd(temp, inp[i]);
    }
    return temp;
}

bool check(vector<int> &arr, int inp_gcd) {
    for (int item : arr) {
        if (item % inp_gcd == 0) return false;
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    // 변수 및 초기화
    int answer = 0;
    int Agcd = gcd(arrayA);
    int Bgcd = gcd(arrayB);
    
    // 확인
    if (check(arrayB, Agcd)) answer = Agcd;
    if (check(arrayA, Bgcd)) answer = max(answer, Bgcd);
    return answer;
}