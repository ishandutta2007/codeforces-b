// kotlin tips b/c I'm bad

/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/** valid ways to sort (avoid quicksort ...)
 * 1
    val a = nextLongs().sorted() // a is mutable list
 * 2
    val a = arrayListOf<Long>() // or ArrayList<Long>()
    a.addAll(nextLongs())
    a.sort()
 */

/** Bit shift
 * 1 shl 20
 */

/** 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
    intArrayOf(8, 9, 1, 13),
    intArrayOf(3, 12, 7, 5),
    intArrayOf(0, 2, 4, 11),
    intArrayOf(6, 10, 15, 14)
    )
 */

/** printing variables:
 * println("${l+1} and $r")
 * evidently print has high constant factor
 * print stringbuilder instead?
 */

/** comparing pairs
    val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
    val pq = PriorityQueue<Pair<Long,Int>>(compareBy {it.first})
 * https://alvinalexander.com/source-code-kotlin-sortedWith-syntax-lambda-examples
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
    sortBy
 */

/** hashmap
 *  val h = HashMap<String,Int>()
    for (i in 0..n-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w){0}
        h.put(w,c+1)
    }
 */

/** swap
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/also.html
 * a = b.also { b = a }
 */

// lower bound: use binary search
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/binary-search.html

// if / switch (when)
// https://kotlinlang.org/docs/reference/control-flow.html

// print d to 8 decimal places: String.format("%.8g%n", d)

// arraylist remove element at index: removeAt, not remove ...

import java.util.*

val MX = 200005
val MOD = 1000000007
val SZ = 1 shl 18
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val xd = arrayOf(1,0,-1,0)
val yd = arrayOf(0,1,0,-1)

val out = StringBuilder()

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }

val ans = ArrayList<ArrayList<Int>>()
val st = ArrayList<Int>()
val adj = Array<ArrayList<Int>>(MX,{ArrayList<Int>()})
val label = Array<ArrayList<Int>>(MX,{ArrayList<Int>()})
val use = BooleanArray(MX)
val inSt = BooleanArray(MX)

fun dfs(x: Int, lab: Int) {
    while (label[x].size > 0) {
        val pos = label[x].size-1
        val LABEL = label[x][pos]
        /*print(x)
        print(" ")
        print(use[LABEL])
        print(" ")
        println(label[x].size)*/
        if (use[LABEL]) {
            adj[x].removeAt(pos)
            label[x].removeAt(pos)
            continue
        }
        use[LABEL] = true
        dfs(adj[x][pos],LABEL)
    }
    if (lab != -1) ans[ans.size-1].add(lab)
}

fun VAL(c: Char): Int {
    return when(c) {
        'k' -> 0
        'o' -> 1
        't' -> 2
        'l' -> 3
        'i' -> 4
        else -> {5}
    }
}

fun cat(s: String): Pair<Int,Int> {
    var b = VAL(s[s.length-1])+1
    if (b == 6) b = 0
    return Pair<Int,Int>(VAL(s[0]),b)
}

fun solve() {
    // write code here
    val n = nextInt()
    for (i in 1..n) {
        val s = next()
        val p = cat(s)
        adj[p.first].add(p.second)
        label[p.first].add(i)
    }
    ans.add(ArrayList())
    dfs(0,-1)
    /*print(ans)
    System.exit(0)*/
    val ret = ans[ans.size-1]
    ret.reverse()
    for (i in ret) out.append("$i ")
    print(out)
}

fun main(args: Array<String>) {
    val t = 1 // # of test cases
    for (i in 1..t) {
        solve()
    }
}