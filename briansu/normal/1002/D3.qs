namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit
    {
        CCNOT(x[0], x[1], y);
        CCNOT(x[2], x[1], y);
        CCNOT(x[2], x[0], y);
    }
}