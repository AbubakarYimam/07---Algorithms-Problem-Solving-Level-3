#include <iostream>
using namespace std;


void fib(int num) {
    int num1=1, num2=1, num3;
    cout << num1 << " " << num2;
    for (int i = 0; i < num -1 ; i++) {
        num3 = num1 + num2;
        cout << " " << num3;
        num1= num2;
        num2 = num3;
    }
}

int main()
{
    fib(100);
}
