import java.util.*

class Solution {
    fun solution(s: String): String {
        var answer = ""
        var array: MutableList<Int> = mutableListOf()
        var str_list = s.split(' ')
        var temp_int: Int = 0
        
        for (item in str_list) {
            array.add(item.toInt())
        }
        
        array.sort()
        
        answer = array[0].toString() + " " + array[array.size-1].toString()
        
        return answer
    }
}