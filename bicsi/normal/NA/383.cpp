fun main() {
    var t = readInt()
    while (t-- > 0) {
        var (a, b) = readInts()
        println(a + b)
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints