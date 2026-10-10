import java.util.*

fun lcm(i1: Int, i2: Int): Int {
    var gcd_temp = gcd(i1, i2)
    var output = (i1 / gcd_temp) * i2
    return output
}

fun gcd(i1: Int, i2: Int): Int {
    if (i2 == 0) return i1
    else return gcd(i2, i1%i2)
}

class Solution {
    fun solution(arr: IntArray): Int {
        var answer = 0
        for (ind in arr.indices) {
            if (ind == 0) {
                answer = arr[ind]
            }
            else {
                answer = lcm(answer, arr[ind])
            }
        }
        
        return answer
    }
}