/**
 * Description: Kotlin tips for dummies
 * Source: https://codeforces.com/blog/entry/71089, Kotlin Reference
 */

/// episode 1: https://codeforces.com/contest/1170
/// episode 2: https://codeforces.com/contest/1211
/// episode 3: https://codeforces.com/contest/1297

import java.io.*
import java.util.* // do NOT use Arrays.sort()

//@JvmField val INPUT = File("inp.txt").inputStream()
@JvmField val INPUT = System.`in`
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
@JvmField val _writer = PrintWriter(OUTPUT, false)
// call _writer.flush() at end
fun rLine(): String? = _reader.readLine()
fun rLn() = rLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer =
        StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun rInt() = read().toInt()
fun rDb() = read().toDouble()
fun rLong() = read().toLong()
fun rStrs(n: Int) = List(n,{read()})
fun rLns(n: Int) = List(n,{rLn()})
fun rInts(n: Int) = List(n,{rInt()})
fun rDbs(n: Int) = List(n,{rDb()})
fun rLongs(n: Int) = List(n,{rLong()})

/**val MOD = 1000000007
val INF = (1e18).toLong()
val SZ = 1 shl 17

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()*/
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)

/**
class BIT() {
val v = LongArray(SZ)
fun upd(_a: Int, b: Long) {
var a = _a
while (a < SZ) {
v[a] += b
a += (a and -a)
}
}
fun query(_a: Int): Long {
var a = _a
var ans: Long = 0
while (a > 0) {
ans += v[a]
a -= (a and -a)
}
return ans
}
}*/

fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5,{IntArray(5,{5})})
    var (x,y) = arrayOf(3,2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0,1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> { println("x is neither 1 nor 2") }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x+2,y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String,Int>()
    val s = "ababa"
    for (i in 0..s.length-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w,{0})
        h.put(w,c+1)
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>({x,y ->
        x.first.compareTo(y.first)}) // or compareBy{it.first}
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
        x.first.compareTo(y.first)}) // or sortBy{it.first}
    val list = arrayListOf('a','b','c','d','e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d')+1) // 3
    list.add(actualInsertPoint, 'd') // [a,b,c,d,e]
    list.removeAt(1) // remove at index -> [a,c,d,e]
}
fun main() {
    val t = rInt()
    for (i in 1..t) {
        val s = read()
        val ans = ArrayList<String>()
        for (j in 0..s.length-1) if (s[j] != '0') {
            var res = s[j].toString()
            for (k in j+1..s.length-1) res += '0'
            ans.add(res)
        }
        println(ans.size)
        for (a in ans) {
            print(a)
            print(' ')
        }
        println()
    }
}