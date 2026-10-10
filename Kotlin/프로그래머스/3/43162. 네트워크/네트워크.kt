import java.util.*

class Solution {
    fun solution(n: Int, computers: Array<IntArray>): Int {
        var touched = BooleanArray(n) {false}
        var answer = 0
        var que = ArrayDeque<Int>()
        
        for (ind in 0..n-1) {
            if (!touched[ind]) {
                touched[ind] = true
                answer += 1
                que.addLast(ind)
            }
            while (!que.isEmpty()) {
                var cur_ind = que.first()
                que.removeFirst()
                for(next_ind in 0..n-1) {
                    if (cur_ind != next_ind && computers[cur_ind][next_ind] == 1 && !touched[next_ind]) {
                        touched[next_ind] = true
                        que.addLast(next_ind)
                    }
                }
            }
        }
        return answer
    }
}