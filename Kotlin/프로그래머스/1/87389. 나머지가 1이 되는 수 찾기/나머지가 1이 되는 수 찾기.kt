import java.util.*

class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 2
        var flag: Boolean = true
        while (flag) {
            if (n % answer == 1) return answer
            else answer += 1
        }
        return answer
    }
}