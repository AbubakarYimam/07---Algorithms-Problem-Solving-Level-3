#include <iostream>
using namespace std;

// Function to print Fibonacci numbers using recursion
void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2) {
    if (Number > 0) {
        int FibNumber = Prev1 + Prev2;

        cout << FibNumber << "   ";

        // Recursive call
        PrintFibonacciUsingRecursion(Number - 1, Prev2, FibNumber);
    }
}

int main() {
    cout << "Fibonacci Sequence: \n";

    // First two numbers of Fibonacci sequence
    cout << 0 << "   " << 1 << "   ";

    // Start recursion for the next 10 numbers
    PrintFibonacciUsingRecursion(10, 0, 1);

    system("pause>0");
    return 0;
}
