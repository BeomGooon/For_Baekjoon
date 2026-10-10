import java.util.*

var map: MutableList<Int> = mutableListOf()
var target_cur: Int = 1

fun dfs(ind: Int, cur_sum: Int): Int {
    if (ind == map.size - 1) {
        if (cur_sum + map[ind] == target_cur || cur_sum - map[ind] == target_cur) return 1
        else return 0
    }
    else {
        var output: Int = dfs(ind + 1, cur_sum + map[ind])
        output += dfs(ind + 1, cur_sum - map[ind])
        return output
    }
}

class Solution {
    fun solution(numbers: IntArray, target: Int): Int {
        var answer = 0
        for (item in numbers) map.add(item)
        target_cur = target
        
        answer = dfs(0, 0)
        return answer
    }
}