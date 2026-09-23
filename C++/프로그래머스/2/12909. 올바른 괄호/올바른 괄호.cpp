#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer;
    int n = s.length();
    int sema = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') {
            sema++;
        }
        else {
            if (sema < 1) {
                return false;
            }
            else {
                sema--;
            }
        }
    }
    answer = (sema == 0);
    return answer;
}