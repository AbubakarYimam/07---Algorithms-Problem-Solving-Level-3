#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int randnum(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void fillmat(int arr[3][3]) {
    for (int i = 0; i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            arr[i][j] = randnum(1, 100);
        }
    }
}

void printmat(int arr[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            cout << setw(3)<< arr[i][j]<<"  ";
        }
        cout << endl;
    }
}

void mulmat (int arr[3][3],int a[3][3],int s[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            s[i][j]= arr[i][j] * a[i][j];
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int a[3][3], b[3][3],c[3][3];
    cout<<"\n matrix 1\n";
    fillmat(a);
    printmat(a);
    cout << "\n matrix 2 \n";
    fillmat(b);
    printmat(b);
    cout << "\n\n\n";
    mulmat(a, b,c);
    printmat(c);
    
}
