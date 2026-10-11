class Solution {
    fun solution(n: Int): Long {
        var answer: Long = 0
        var dp = mutableListOf<Long>()
        
        dp.add(0)
        dp.add(1)
        dp.add(2)
        for (item in 3..n) {
            dp.add((dp[item-1] + dp[item-2]) % 1234567)
        }
        
        answer = dp[n]
        return answer
    }
}