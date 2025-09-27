#include <iostream>
#include <iomanip>
using namespace std;

void printmatrix(int arr[3][3]) {
    int s = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            s++;
            arr[i][j]=s;
            cout <<setw(3)<< s;
        }
        cout << "\n";
    }
}

void printtrans(int arr[3][3]) {
    for (int i = 0; i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            cout <<setw(3)<< arr[j][i];
        }
        cout << "\n";
    }
}

int main()
{
    int a[3][3];
    printmatrix(a);
    printtrans(a);
}