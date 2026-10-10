import java.util.*

class Solution {
    fun solution(n: Int): Int {
        var answer = 0
        var cur: Int = n

        while (cur > 0) {
            answer += cur % 10
            cur /= 10
        }

        return answer
    }
}