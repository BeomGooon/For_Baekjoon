#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) { // a가 b보다 크다고 가정
    if (b) {
        int temp = gcd(b, a % b);
        return temp;
    }
    else {
        return a;
    }
}

int lcm(int a, int b) {
    int temp_gcd = gcd(a, b);
    return (a * b / temp_gcd);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    int temp = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        temp = lcm(temp, arr[i]);
        answer = temp;
    }
    return answer;
}